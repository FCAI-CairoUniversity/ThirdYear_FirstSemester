public class VIPCustomerDiscount implements IDiscount{
    double discount = 0.3;

    @Override
    public void discount(double total) {
        System.out.println("VIP Customer discount");
        total -= (total * discount);
        System.out.println("Total Price after discount = " + total + "$");
    }
}
