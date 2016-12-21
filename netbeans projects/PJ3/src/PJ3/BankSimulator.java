package PJ3;

import java.util.*;
import java.io.*;

// You may add new functions or data in this class 
// You may modify any functions or data members here
// You must use Customer, Teller and ServiceArea
// to implement your simulator

class BankSimulator {

  // input parameters
  private int numTellers, customerQLimit;
  private int simulationTime, dataSource;
  private int chancesOfArrival, maxTransactionTime;

  // statistical data
  private int numArrived, numGoaway, numServed, totalWaitingTime;

  // internal data
  private int customerIDCounter;
  private ServiceArea servicearea; // service area object
  private Scanner dataFile;	   // get customer data from file
  private Random dataRandom;	   // get customer data using random function
  private int currentTime;
  
  // most recent customer arrival info, see getCustomerData()
  private boolean anyNewArrival;  
  private int transactionTime;

  // initialize data fields
  private BankSimulator()
  {
	  numArrived =0;
	      numGoaway=0;
	      numServed=0;
	      totalWaitingTime=0;
  }

  private void setupParameters()
  {
	
	  // read input parameters
	// setup dataFile or dataRandom
	  
	     Scanner userParameter = new Scanner(System.in);

	     System.out.print("Enter simulation time (positive integer)       : ");
	     simulationTime = userParameter.nextInt();

	     System.out.print("Enter maximum transaction time of customers    : ");
	     maxTransactionTime = userParameter.nextInt();

	     System.out.print("enter chances (0% < & <= 100%) of new customer : ");
	     chancesOfArrival = userParameter.nextInt();

	     System.out.print("Enter the number of tellers                    : ");
	     numTellers = userParameter.nextInt();

	     System.out.print("Enter customer queue limit                     : ");
	     customerQLimit = userParameter.nextInt();

	     System.out.print("Enter 1/0 to get data from file/Random         : ");
	     dataSource = userParameter.nextInt();

    String fileName = userParameter.nextLine(); // a hack to get rid of the lingering newline

    switch(dataSource) {
      case 0:
        System.out.println("Set random seed to default...");
        
        dataRandom = new Random(); //initialize the pseudo-random number generator
        boolean anyNewArrival = ((dataRandom.nextInt(100)+1) <= chancesOfArrival);
        int transactionTime = dataRandom.nextInt(maxTransactionTime)+1;
        break;
       case 1:
    	   
    	   System.out.print("Enter filename                                 : ");

    	           fileName = userParameter.nextLine().trim(); // here the user will type the file name

    	           //in case the file ain't there, we catch the error
    	           try{
    	             File file = new File(fileName);
    	             dataFile = new Scanner(file);
    	           }
    	           catch (FileNotFoundException e ) {
    	             e.printStackTrace();
    	            }
    	    
    	           break;
    	         default:
    	           break;
    	        }

    
    
  }

  private void getCustomerData()
  {
	  int data1 = 0;
	     int data2 = 0;
	     switch (dataSource){
	       case 0:
	         //in this case, we get random data anyNewArrival and transactionTime
	         anyNewArrival = ((dataRandom.nextInt(100)+1) <= chancesOfArrival);
	         transactionTime = dataRandom.nextInt(maxTransactionTime)+1;
	         break;
	       case 1:
	    	   
	  if (dataFile.hasNextLine()){
		        String line = dataFile.nextLine();
		        String[] parts = line.split(" ");
		        data1 = Integer.parseInt(parts[0]);
		        data2 = Integer.parseInt(parts[1]);
		      }
	  anyNewArrival = (((data1%100)+1)<= chancesOfArrival);
      transactionTime = (data2%maxTransactionTime)+1;
      break;
	     
	     }
	      // get next customer data : from file or random number generator
	      // set anyNewArrival and transactionTime
	      // add statements
  }

  private void doSimulation()
  {
	  System.out.println("Customer #1 to #" +customerQLimit + " are ready...\n\n");
	  System.out.println("---------------------------------------------");
	  int initialTellerID = 1;
	     customerIDCounter = 1;
	// Initialize ServiceArea
	      servicearea = new ServiceArea(numTellers, customerQLimit, 1001);
	      Customer customer;
	      Customer c1;
	      Teller p1;
	      
	// Time driver simulation loop
  	for (int currentTime = 0; currentTime < simulationTime; currentTime++) {
  		
  		System.out.printf("Time : %d \n", currentTime);
  		
  		// Step 1: any new customer enters the bank?
    		getCustomerData();

    		if (anyNewArrival) {

      		    // Step 1.1: setup customer data
    			numArrived++;
    			customer = new Customer(customerIDCounter, transactionTime, currentTime); //customer id, transactionTime, currentTime
    			System.out.printf("\tcustomer #%d arrives with transaction time %d units \n", customer.getCustomerID(), customer.getTransactionTime());
    			customerIDCounter++; // increment the customerIDCounter
    			
    			
      		    // Step 1.2: check customer waiting queue too long?
    			if (!servicearea.isCustomerQTooLong()) {
    				servicearea.insertCustomerQ(customer);
    				System.out.printf("\tcustomer #%d is waiting the customer queue \n", customer.getCustomerID());
    				} else {
    					System.out.printf("\tcustomer #%d is waiting the customer queue \n", customer.getCustomerID());
    					numGoaway++;
    		} 
    			} else {
    		          System.out.println("\tNo new arrivals");
    		          System.out.println("---------------------------------------------");
    		        }

    		// Step 2: free busy tellers, add to free tellerQ
    		while (!servicearea.emptyBusyTellerQ() && servicearea.getFrontBusyTellerQ().getEndBusyIntervalTime() == currentTime) {
    	         p1 = servicearea.getFrontBusyTellerQ();
    	         c1 = p1.busyToFree(); //we match a customer with a teller -- who is now busy
    	         System.out.printf("\tcustomer #%d is done\n", p1.getCustomer().getCustomerID());
    	         numServed++;
    	         System.out.printf("\tteller #%d is free\n", p1.getTellerID());
    	         servicearea.insertFreeTellerQ( servicearea.removeBusyTellerQ() );
    	       }
    		
    		
    		
    		// Step 3: get free tellers to serve waiting customers 
    		
    		
    		
    		while ( !servicearea.emptyFreeTellerQ() &&  !servicearea.emptyCustomerQ() )  {
        c1 = servicearea.removeCustomerQ(); //pops a customer from line, and stores in c1 
        System.out.printf("\tcustomer #%d gets a teller \n", c1.getCustomerID());
        totalWaitingTime += currentTime - c1.getArrivalTime(); //add customer's waiting time
        p1 = servicearea.removeFreeTellerQ(); //pops a teller from freeTellerQ, and stores in p1
        p1.freeToBusy(c1, currentTime); //we match a customer wit a teller -- who is now busy
        servicearea.insertBusyTellerQ(p1); //inserts teller to busyTellerQ
        System.out.printf("\tteller #%d starts serving customer #%d for %d units\n", p1.getTellerID(), c1.getCustomerID(), c1.getTransactionTime());
        System.out.printf("---------------------------------------------\n");
    		}
    } // end simulation loop
  	// clean-up
  }

  private void printStatistics()
  {
	  Teller p1;
	  System.out.println("\n============================================\n");
	  System.out.println("End of simulation report\n");
	  System.out.printf("\t# total arrival customers : %d\n",numArrived);
	  System.out.printf("\t# customers gone-away     : %d\n",numGoaway);
	  System.out.printf("\t# customers served        : %d\n\n",numServed + servicearea.numBusyTellers());

	  
	  System.out.println("\t*** Current Tellers Info. ***\n\n");
	  System.out.printf("\t# waiting customers : %d\n",servicearea.numWaitingCustomers());
	  System.out.printf("\t# busy tellers      : %d\n",servicearea.numBusyTellers());
	  System.out.printf("\t# free tellers      : %d\n",servicearea.numFreeTellers());

	  System.out.printf("\t# Total waiting time         : %d\n",totalWaitingTime);
	  System.out.printf("\t# Average waiting time       : %.2f\n\n",(float)(totalWaitingTime/(numServed + servicearea.numBusyTellers() ) ) );
	  
	  System.out.println("\tBusy Tellers Info. :");
	       while ( !servicearea.emptyBusyTellerQ())  {
	         p1 = servicearea.removeBusyTellerQ();
	         p1.setEndIntervalTime(currentTime,0);
	         p1.printStatistics();
	       }
	       System.out.println("\tFree Tellers Info. :");
	       while ( !servicearea.emptyFreeTellerQ())  {
	         p1 = servicearea.removeFreeTellerQ();
	         p1.setEndIntervalTime(currentTime, 1);
	         p1.printStatistics();
	       }
  }

  // *** main method to run simulation ****

  public static void main(String[] args) {
   	BankSimulator runBankSimulator=new BankSimulator();
   	runBankSimulator.setupParameters();
   	runBankSimulator.doSimulation();
   	runBankSimulator.printStatistics();
  }

}
