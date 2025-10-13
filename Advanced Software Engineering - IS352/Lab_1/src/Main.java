public class Main {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart(new PayPalPayment());
        cart.addItem("Book", 12.99);
        cart.addItem("Pen", 1.49);
        cart.addItem("Notebook", 5.99);
        cart.checkout();

        System.out.println();

        cart = new ShoppingCart(new CreditCardPayment());
        cart.addItem("Laptop", 899.99);
        cart.addItem("Keyboard", 12.99);
        cart.checkout();
    }
}