public class VoucherDiscount implements IDiscount{
    double discount = 0.25;

    @Override
    public void discount(double total) {
        System.out.println("Voucher discount");
        total -= (total * discount);
        System.out.println("Total Price after discount = " + total + "$");
    }
}
