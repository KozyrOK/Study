public class Gun {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;
    
    Gun(String model, int capacity) {
       this.capacity = capacity;
       this.model = model;
       this.amount = 0;
       this.totalShots = 0;
       this.isReady = false;
    }

    int getAmount() {
        return this.amount;
    }

    int getCapacity() {
        return this.capacity;
    }

    boolean ready() {
        return this.isReady;
    }
    
    String getModel() {
        return this.model;
    }

    int getTotalShots() {
        return this.totalShots;
    }

    void prepare() {
        this.isReady = true;
    }

    void reload(){
        this.amount = capacity;
    }

    void shoot() throws NotReadyException, OutOfRoundsException {
        if (this.isReady == false) {
            throw new NotReadyException ();
        }
        if (amount == 0) {
            throw new OutOfRoundsException();
        }
        System.out.println("Bang!");
        amount -=1;
        totalShots +=1;
    }
    
    public void print(){
        System.out.println("Gun model: "+this.model+"\n"
                            +"Amount: " + this.amount+"\n"
                            +"Capacity: " + this.capacity+ "\n"
                            +"Gun ready: " + this.isReady+ "\n" 
                            +"Total shots: " +this.totalShots);
    }
}
