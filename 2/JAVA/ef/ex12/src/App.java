interface Button {
    void draw();
}
interface Checkbox {
    void draw();
}
interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}
class WindowsButton implements Button {
    public void draw() {
        System.out.println("Windows button");
    }
}
class WindowsCheckbox implements Checkbox {
    public void draw() {
        System.out.println("Windows checkbox");
    }
}

class MacOSButton implements Button {
    public void draw() {
        System.out.println("MacOS button");
    }
}
class MacOSCheckbox implements Checkbox {
    public void draw() {
        System.out.println("MacOS checkbox");
    }
}

class WindowsGUIFactory implements GUIFactory {
    public Button createButton() {
        return new WindowsButton();
    }
    public Checkbox createCheckbox() {
        return new WindowsCheckbox();
    }
}
class MacOSGUIFactory implements GUIFactory {
    public Button createButton() {
        return new MacOSButton();
    }
    public Checkbox createCheckbox() {
        return new MacOSCheckbox();
    }
}

public class App {
    public static void main(String[] args) {
        GUIFactory factory = null;
        String[] os = {"Windows", "MacOS"};
        for (String osName : os){
            if (osName.equals("Windows")) {
                factory = new WindowsGUIFactory();
            }
            else if (osName.equals("MacOS")) {
                factory = new MacOSGUIFactory();
            }
            Button button = factory.createButton();;
            Checkbox checkbox = factory.createCheckbox();
            button.draw();
            checkbox.draw();
        }
    }
}