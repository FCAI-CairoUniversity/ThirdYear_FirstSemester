public class ShoppingCart {
    double total;

    public ShoppingCart() {}

    public void addItem(double item) {
        total +=  item;
    }

    public void applyDiscount(IDiscount discount) {
        discount.discount(total);
    }
}
