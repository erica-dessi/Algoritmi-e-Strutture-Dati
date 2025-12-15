package priorityqueue;

/**
 * Custom exception class for handling errors related to priority queue operations.
 */
public class PriorityQueueException extends Exception {

    /**
     * Constructs a new {@code PriorityQueueException} with the specified detail message.
     *
     * @param message the detail message
     */
    public PriorityQueueException(String message) {
        super(message);
    }
}
