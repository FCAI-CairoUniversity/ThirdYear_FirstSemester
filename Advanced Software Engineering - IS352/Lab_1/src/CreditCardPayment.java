public class CreditCardPayment implements IPaymentMethod{
    @Override
    public void pay() {
        System.out.println("Processing credit card payment...");
    }
}
