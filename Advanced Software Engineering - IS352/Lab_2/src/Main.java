import java.util.*;

public class Main {
    public static void main(String[] args) {

        ShoppingCart cart = new ShoppingCart();

        cart.addItem(10);
        cart.addItem(20);
        cart.addItem(30);
        cart.addItem(40);
        cart.addItem(50);

        cart.applyDiscount(new VIPCustomerDiscount());
    }
}