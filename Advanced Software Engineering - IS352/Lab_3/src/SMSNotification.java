public class SMSNotification implements NotificationDecorator {
    private Notification notification;

    public SMSNotification(Notification notification) {
        this.notification = notification;
    }

    @Override
    public void sendNotification() {
        if (notification != null)
            notification.sendNotification();
        System.out.println("SMS Notification");
    }
}
