package serialCommunication;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

class MatrixPanel extends JPanel {
    private final ArrayList<ArrayList<PixelPanel>> pixelStorage;

    MatrixPanel() {
        //size of the matrix is dependant on the main height, chosen to fit all SliderPanel elements vertical
        //noinspection SuspiciousNameCombination
        setPreferredSize(new Dimension(Main.contentHeight, Main.contentHeight));
        setBackground(Color.BLACK);
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.BOTH;
        gbc.weightx = 0.5;
        gbc.weighty = 0.5;

        pixelStorage = new ArrayList<>();

        gbc.gridx = 0;
        gbc.gridy = 0;

        for (int i = 0; i < Main.pixelsY; i++) {
            pixelStorage.add(new ArrayList<>());
            for (int j = 0; j < Main.pixelsX; j++) {
                if (i % 2 == 0) {
                    pixelStorage.get(i).add(new PixelPanel(j % 2 == 0 ? new Color(200, 200, 200) : new Color(230, 230, 230)));
                } else {
                    pixelStorage.get(i).add(new PixelPanel(j % 2 == 0 ? new Color(230, 230, 230) : new Color(200, 200, 200)));
                }

                gbc.gridx++;
                add(pixelStorage.get(i).get(j), gbc);
            }
            gbc.gridx = 0;
            gbc.gridy++;
        }
        revalidate();
        repaint();

    }

    public void resetColor() {
        for (ArrayList<PixelPanel> row : pixelStorage) {
            for (PixelPanel pixel : row) {
                pixel.restoreColor();
            }
        }
    }

    public void updateColors(int[] dataArray) {
        //int index = 7;
        int index = 0;

        int xOffset = 0;
        int yOffset = 0;
        for (int x = 0; x < 4; x++) {
            switch (x) {
                case 1:
                    //chunk  NE
                    xOffset = 10;
                    break;
                case 2:
                    //chunk SW
                    xOffset = 0;
                    yOffset = 10;
                    break;
                case 3:
                    //chunk SE
                    xOffset = 10;
                    break;
            }
            for (int i = yOffset; i < Main.pixelsY / 2 + yOffset; i++) {
                for (int j = xOffset; j < Main.pixelsX / 2 + xOffset; j++) {
                    pixelStorage.get(i).get(j).changeColour(dataArray[index], dataArray[index + 1], dataArray[index + 2]);
                    index += 3;
                }
            }
        }
        repaint();

    }
}
