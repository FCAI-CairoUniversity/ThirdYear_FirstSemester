public class ShoppingCart {
    private IPaymentMethod paymentMethod;
    private double totalPrice;

    ShoppingCart(IPaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    public void addItem(String item, double price) {
        totalPrice += price;
    }

    public void checkout() {
        if (paymentMethod == null) {
            System.out.println("No payment method selected.");
        }
        else if (totalPrice == 0) {
            System.out.println("Your cart is empty.");
        }
        else {
            System.out.println("Total price: " + totalPrice + "$");
            paymentMethod.pay();
        }
    }
}
