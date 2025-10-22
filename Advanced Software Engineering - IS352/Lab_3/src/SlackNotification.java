public class SlackNotification implements NotificationDecorator {
    private Notification notification;

    public SlackNotification(Notification notification) {
        this.notification = notification;
    }

    @Override
    public void sendNotification() {
        if (notification != null)
            notification.sendNotification();
        System.out.println("Slack Notification");
    }
}
