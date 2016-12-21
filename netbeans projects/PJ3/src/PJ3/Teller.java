// DO NOT ADD NEW METHODS OR DATA FIELDS!

package PJ3;

class Teller {

   // start time and end time of current interval
   private int startTime;
   private int endTime;

   // teller id and current customer which is served by this teller 
   private int tellerID;
   private Customer currentCustomer;

   // for keeping statistical data
   private int totalFreeTime;
   private int totalBusyTime;
   private int totalCustomers;

   // Constructor
   Teller()
   {
	// add statements
	   tellerID=0;
	   totalFreeTime=0;
	   totalBusyTime=0;
	   totalCustomers=0;
   }

   
   // Constructor with teller id
   Teller(int tellerId)
   {
	// add statements
	   this.tellerID= tellerId;
	   totalFreeTime=0;
	   totalBusyTime=0;
	   totalCustomers=0;
   }

   // accessor methods

   int getTellerID () 
   {
	return tellerID;
   }

   Customer getCustomer() 
   {
	// add statements
	return currentCustomer;
   }

   // need this to setup priority queue
   int getEndBusyIntervalTime() 
   {
        // return end time of busy interval
	// add statements
	
	   return endTime; 
   }

   // functions for state transition
   // FREE -> BUSY :
   void freeToBusy (Customer currentCustomer, int currentTime)
   {
  	
	   // Main goal  : switch from free interval to busy interval
  	//
  	// end free interval, start busy interval
  	// steps	: update totalFreeTime
	   endTime = currentTime;
	   totalFreeTime += (endTime - startTime);

	// add statements
	   
	   startTime = currentTime; //TODO ¿Or is it +1?
	   endTime = currentCustomer.getTransactionTime() + startTime;
	   this.currentCustomer = currentCustomer;


	   totalCustomers++;

   
   }

   // BUSY -> FREE :
   Customer busyToFree ()
   {
   	// Main goal : switch from busy interval to free interval
   	// 
  	// steps     : update totalBusyTime 
	   totalBusyTime += (endTime - startTime);
  	// 	       set startTime 
	   startTime = endTime;//TODO see if this works or if + 1
  	//             return currentCustomer
	   return currentCustomer;
   }

   // need this method at the end of simulation to update teller data
   void setEndIntervalTime (int endsimulationtime, int intervalType)
   {
  	// for end of simulation
  	// set endTime, 
	   endTime = endsimulationtime;
  	// for FREE interval, update totalFreeTime
	   if ( intervalType ==1 ) {
		   
		   
		   totalFreeTime += (endsimulationtime - startTime);
		   
  	// for BUSY interval, update totalBusyTime
		   }else{
			   
			   totalBusyTime += (endsimulationtime - startTime);
		   }

   }

   // functions for printing statistics :
   void printStatistics () 
   {
  	// print teller statistics, see project statement

  	System.out.println("\t\tTeller ID                : "+tellerID);
  	System.out.println("\t\tTotal free time          : "+totalFreeTime);
  	System.out.println("\t\tTotal busy time          : "+totalBusyTime);
  	System.out.println("\t\tTotal # of customers     : "+totalCustomers);
  	if (totalCustomers > 0)
  	   System.out.format("\t\tAverage transaction time : %.2f%n\n",(totalBusyTime*1.0)/totalCustomers);
   }

   public String toString()
   {
	return "Teller:"+tellerID+":"+startTime+"-"+endTime+":Customer:"+currentCustomer;
   }

   public static void main(String[] args) {
        // quick check
        Customer mycustomer = new Customer(20,30,40);
	Teller myteller = new Teller(5);
        myteller.freeToBusy (mycustomer, 13);
        System.out.println(myteller);

   }

};

