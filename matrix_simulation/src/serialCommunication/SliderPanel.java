package serialCommunication;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

class SliderPanel extends JPanel {
    private final ArrayList<JSlider> faders;
    private final ArrayList<JLabel> faderLabels;

    private final JLabel bottomSwitchText;
    private final JLabel fpsText;

    private final JComboBox<String> portDropDown;

    SliderPanel() {
        //set layout and size
        setLayout(new GridBagLayout());
        setMinimumSize(new Dimension(250, Main.contentHeight));
        setPreferredSize(new Dimension(250, Main.contentHeight));
        setMaximumSize(new Dimension(250, Main.contentHeight));

        //configure GridBagConstraints
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.weightx = 0.5;
        gbc.weighty = 0.5;
        gbc.fill = GridBagConstraints.HORIZONTAL;

        faders = new ArrayList<>();
        faderLabels = new ArrayList<>();
        for (int i = 0; i < 6; i++) {
            faders.add(new JSlider(0, 1023));
            faders.get(i).setEnabled(false);
            faderLabels.add(new JLabel("Fader " + (i + 1)));
        }


        bottomSwitchText = new JLabel("Matrix Mode");
        fpsText = new JLabel("FPS: -");

        portDropDown = new JComboBox<>(new String[]{SliderPanelConstants.NO_PORTS_AVAILABLE_MESSAGE});

        JButton portRefreshButton = new JButton(SliderPanelConstants.REFRESH_BUTTON_TEXT);
        portRefreshButton.addActionListener(e -> Main.getPorts());

        JButton portSelectButton = new JButton(SliderPanelConstants.SELECT_BUTTON_TEXT);
        portSelectButton.addActionListener(e -> Main.selectPort(portDropDown.getSelectedIndex()));

        JButton portDisconnectButton = new JButton(SliderPanelConstants.DISCONNECT_BUTTON_TEXT);
        portDisconnectButton.addActionListener(e -> Main.disconnectFlag = true);


        gbc.ipady = 10;
        gbc.gridx = 0;
        gbc.gridy = 0;

        for (int i = 0; i < 6; i++) {
            add(faderLabels.get(i), gbc);
            gbc.gridy++;
            add(faders.get(i), gbc);
            gbc.gridy++;
        }

        add(bottomSwitchText, gbc);
        gbc.gridy++;
        add(fpsText, gbc);
        gbc.gridy++;
        add(portDropDown, gbc);
        gbc.gridy++;
        add(portRefreshButton, gbc);
        gbc.gridy++;
        add(portSelectButton, gbc);
        gbc.gridy++;
        add(portDisconnectButton, gbc);

    }

    public void removePortsList() {
        portDropDown.removeAllItems();
    }

    public void updatePortsList(String item) {
        portDropDown.addItem(item);

    }

    public void setValue(int[] faderValues, int bottomSwitch, double fps) {
        for (int i = 0; i < 6; i++) {
            faders.get(i).setValue(faderValues[i]);
            faderLabels.get(i).setText("Fader " + (i + 1) + "     " + faderValues[i]);
        }

        if (bottomSwitch == 1) bottomSwitchText.setText("Extend Matrix Mode");
        else bottomSwitchText.setText("Duplicate Matrix Mode");

        fpsText.setText("FPS: " + Math.round(fps));
    }
}
