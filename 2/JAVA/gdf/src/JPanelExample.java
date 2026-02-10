import javax.swing.*;
import java.awt.*;
public class JPanelExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("JPanel Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
// JPanel с FlowLayout
        JPanel panel1 = new JPanel();
        panel1.setLayout(new FlowLayout()); // FlowLayout
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        panel1.add(button1);
        panel1.add(button2);
// JPanel с BorderLayout
        JPanel panel2 = new JPanel();
        panel2.setLayout(new BorderLayout()); //BorderLayout
        JLabel label = new JLabel("Center Label", SwingConstants.CENTER);
        JButton button3 = new JButton("North");
        panel2.add(label, BorderLayout.CENTER);
        panel2.add(button3, BorderLayout.NORTH);
        frame.getContentPane().add(panel1, BorderLayout.NORTH);
        frame.getContentPane().add(panel2, BorderLayout.CENTER);
        frame.setVisible(true);
    }
}