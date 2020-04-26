package serialCommunication;


import javax.swing.*;
import java.awt.*;

class PixelPanel extends JPanel {
    private final Color originalColor;

    PixelPanel(Color color) {
        this.originalColor = color;
        setBackground(color);
    }

    public void changeColour(int red, int green, int blue) {
        if (red > 255)
            red = 255;
        if (green > 255)
            green = 255;
        if (blue > 255)
            blue = 255;

        setBackground(new Color(red, green, blue));
        revalidate();
        repaint();
    }

    public void restoreColor() {
        setBackground(originalColor);
    }
}
