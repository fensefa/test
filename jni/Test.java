public class Test {
    public native int intMethod(int n);
    public native String stringMethod(String text);
    public static void main(String[] args) {
        Test test = new Test();
        System.out.println(test.intMethod(3));
        System.out.println(test.stringMethod("abc"));
    }
    static {
        System.loadLibrary("test");
    }
}
