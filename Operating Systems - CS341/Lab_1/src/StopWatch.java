public class StopWatch {
    public static void main(String[] args) {
        int seconds = 10;

        while (seconds > 0) {
            System.out.println(seconds);
            seconds--;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Time's up!");
    }
}