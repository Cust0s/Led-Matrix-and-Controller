package serialCommunication;

import com.fazecast.jSerialComm.SerialPort;

import javax.swing.*;
import java.awt.*;
import java.util.Arrays;
import java.util.Scanner;

import static javax.swing.BorderFactory.createEmptyBorder;

class Main {
    private static final String FRAME_TITLE = "LED Matrix Simulation";
    private static final String FRAME_TITLE_EXTENSION = " - Not Connected";

    public static final int contentHeight = 500;
    static final int pixelsY = 20;
    static final int pixelsX = 20;
    private static final int dataPoints = pixelsY * pixelsX * 3 + 7;  //307 for a 10x10 matrix

    private static double fpsAverage;

    private static SerialPort[] ports;
    private static SerialPort serialPort;

    private static SliderPanel sliderPanel;
    private static MatrixPanel matrixPanel;

    private static JFrame frame;

    private static volatile boolean processNewPort = false;
    static volatile boolean disconnectFlag = false;

    public static void main(String[] args) {
        frame = new JFrame(FRAME_TITLE + FRAME_TITLE_EXTENSION);

        sliderPanel = new SliderPanel();
        //create an empty border to add enough space to the panel as to not have content blocked by the scrollbar
        sliderPanel.setBorder(createEmptyBorder(20, 20, 20, 20));
        JScrollPane sliderScrollPane = new JScrollPane(sliderPanel);
        sliderScrollPane.setBorder(BorderFactory.createMatteBorder(1, 1, 1, 1, Color.GRAY));
        sliderScrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
        frame.add(sliderScrollPane, BorderLayout.WEST);
        matrixPanel = new MatrixPanel();
        frame.add(matrixPanel);
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        //keep checking if the processNewPort flag has been set true by the user clicking the select button
        //noinspection InfiniteLoopStatement
        while (true) {
            if (processNewPort) {
                frame.revalidate();
                frame.repaint();
                //process the selected port (will end up locked in a loop until device is disconnected
                try {
                    processPort();
                } catch (NullPointerException e) {
                    //ignore NullPointerException if one occurs
                }
                frame.revalidate();
                frame.repaint();
            }
        }
    }

    //can sometimes throw NullPointerException for the Scanner/serialPort when it is connecting to a port and the
    //disconnect button is pressed while connection is being established
    private static void processPort() throws NullPointerException {
        processNewPort = false;
        serialPort.setComPortTimeouts(SerialPort.TIMEOUT_SCANNER, 0, 0);
        serialPort.setBaudRate(115200);

        int timeDelay;
        long lastTime;
        Scanner dataScanner = new Scanner(serialPort.getInputStream());
        int[] dataArray = new int[dataPoints];
        lastTime = System.currentTimeMillis();
        int fpsAverageCounter = 0;
        double fpsRaw = 0;
        while (dataScanner.hasNextLine() && !disconnectFlag) {
            String receivedData = dataScanner.nextLine();
            String[] inputArray;
            inputArray = receivedData.split(",", dataPoints);

            for (int j = 0; j < inputArray.length; j++) {
                try {
                    dataArray[j] = Integer.parseInt(inputArray[j]);
                } catch (NumberFormatException e) {
                    dataArray[j] = 1023;
                }
            }
            int bottomSwitch = dataArray[6];

            sliderPanel.setValue(Arrays.copyOfRange(dataArray, 0, 6), bottomSwitch, fpsAverage);
            matrixPanel.updateColors(Arrays.copyOfRange(dataArray, 7, dataArray.length));


            if (fpsAverageCounter == 5) {
                fpsAverage = fpsRaw / 5;
                fpsAverageCounter = 0;
                fpsRaw = 0;
            } else {
                fpsRaw += 1000.0 / (System.currentTimeMillis() - lastTime); //one second divided by amount of time it takes for one frame to finish
                lastTime = System.currentTimeMillis();
                fpsAverageCounter++;
            }
        }

        //reset the disconnect flag raised by the disconnect button on the sliderPanel
        disconnectFlag = false;
        frame.setTitle(FRAME_TITLE + FRAME_TITLE_EXTENSION);
        matrixPanel.resetColor();   //reset the colour of each pixel back to the default
        JOptionPane.showMessageDialog(frame,
                "Device was disconnected.",
                "Device Disconnect",
                JOptionPane.ERROR_MESSAGE);

        lastTime = System.currentTimeMillis();
        timeDelay = 100;
        //wait for the system to register the disconnect and then refresh the ports
        //noinspection StatementWithEmptyBody
        while (System.currentTimeMillis() < lastTime + timeDelay) ;

        getPorts();
    }

    public static void selectPort(int selectedPort) {
        //close the serial port if it is open
        if (serialPort != null && serialPort.isOpen()) {
            //reset frame title once the connection has been closed
            frame.setTitle(FRAME_TITLE + FRAME_TITLE_EXTENSION);
            serialPort.closePort();
            matrixPanel.resetColor();   //reset the colour of each pixel back to the default
        }

        //if the drop down displayed that no ports are available, this can send an invalid port when the
        //port array is empty also on first start, ports can be null
        if (ports == null || selectedPort >= ports.length) {
            JOptionPane.showMessageDialog(frame,
                    "No ports available, please refresh.",
                    "Port Error",
                    JOptionPane.ERROR_MESSAGE);
            return;
        }

        serialPort = ports[selectedPort];
        if (serialPort.openPort()) {
            frame.setTitle(FRAME_TITLE + " - " + ports[selectedPort].getDescriptivePortName());
            processNewPort = true;
            //reset disconnect flag. If not connected and disconnect button is pressed, this flag will be true
            //and results in immediate disconnect if not corrected in this way
            if (disconnectFlag)
                disconnectFlag = false;
        } else {
            JOptionPane.showMessageDialog(frame,
                    "Chosen port unavailable, try again after refreshing.",
                    "Port Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void getPorts() {
        //get the currently connected com ports
        ports = SerialPort.getCommPorts();
        //remove the old ports from the drop down list
        sliderPanel.removePortsList();
        //if no ports are available, put the appropriate message
        if (ports.length == 0) {
            sliderPanel.updatePortsList(SliderPanelConstants.NO_PORTS_AVAILABLE_MESSAGE);
        } else { //if ports are available
            //add the available ports to the drop down list
            for (SerialPort port : ports) {
                sliderPanel.updatePortsList(port.getSystemPortName());
            }
        }
    }

    @SuppressWarnings("unused")
    public static void printValueMatrices(int[] dataArray) {
        for (int i = 7; i < dataArray.length; i += 3) {
            //System.out.print(" " + i + " " + (i-7) % 30 + " ");
            System.out.format("|   %3d,%3d,%3d   ", dataArray[i], dataArray[i + 1], dataArray[i + 2]);
            if ((i - 7) % 30 == 27 && i != 7) {
                System.out.print("|\n");
            }
        }
        System.out.println("\n\n\n");
    }
}
