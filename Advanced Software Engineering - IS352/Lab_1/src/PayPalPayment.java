public class PayPalPayment implements IPaymentMethod {
    @Override
    public void pay() {
        System.out.println("Processing PayPal payment...");
    }
}
