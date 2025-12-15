package graph;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

/**
 * A test runner for executing JUnit tests in the {@link GraphTest} class.
 */
public class GraphTestRunner {
  
    /**
     * The main method to run the JUnit tests and display the results.
     *
     * @param args command-line arguments (not used)
     */
    public static void main(String[] args) {
        // Run the tests from the GraphTest class
        Result result = JUnitCore.runClasses(GraphTest.class);
        
        // Print the details of any test failures
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        
        // Print whether all tests were successful
        System.out.println(result.wasSuccessful());
    }
}
