package priorityqueue;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 * Class to run JUnit tests for the {@link PriorityQueue} class.
 */
public class PriorityQueueTestsRunner {
    
    /**
     * Main method to execute the JUnit tests.
     * 
     * @param args command line arguments (not used in this class)
     */
    public static void main(String[] args) {
        // Run the JUnit tests for the PriorityQueueTests class
        Result result = JUnitCore.runClasses(PriorityQueueTests.class);

        // Print details of any failed tests
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }

        // Print whether all tests were successful
        System.out.println(result.wasSuccessful());
    }
}
