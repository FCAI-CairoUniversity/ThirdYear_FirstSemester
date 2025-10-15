public class CashbackDiscount implements IDiscount{
    double discount = 0.2;

    @Override
    public void discount(double total) {
        System.out.println("Cashback discount");
        total -= (total * discount);
        System.out.println("Total Price after discount = " + total + "$");
    }
}
