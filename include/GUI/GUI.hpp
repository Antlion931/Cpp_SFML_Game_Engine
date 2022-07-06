class Singleton {
    public static Singleton object = null;
   
    public void singleton() {
        if (object == null)
            object = new Singleton();
        return object;
   }
}
