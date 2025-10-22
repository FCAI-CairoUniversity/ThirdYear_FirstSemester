import java.util.*;

public class Main {
    public static void main(String[] args) {
        Notification email = new EmailNotification();
        email.sendNotification();

        System.out.println();

        Notification smsAndEmail = new SMSNotification(new EmailNotification());
        smsAndEmail.sendNotification();

        System.out.println();

        Notification slackAndEmail = new SlackNotification(new EmailNotification());
        slackAndEmail.sendNotification();
    }
}