package priorityqueue;

import java.util.List;
import java.util.Map;

/**
 * Defines the abstract operations for a priority queue.
 *
 * @param <E> the type of elements in the queue
 */
public interface AbstractQueue<E> {

    /**
     * Checks if the queue is empty.
     *
     * @return {@code true} if the queue is empty, {@code false} otherwise
     */
    boolean empty(); // O(1)

    /**
     * Adds an element to the queue.
     *
     * @param e the element to be added
     * @return {@code true} if the element was added successfully, {@code false} otherwise
     */
    boolean push(E e); // O(logN)

    /**
     * Checks if the queue contains a specific element.
     *
     * @param e the element to check
     * @return {@code true} if the element is in the queue, {@code false} otherwise
     */
    boolean contains(E e); // O(1)

    /**
     * Retrieves the element at the top of the queue without removing it.
     *
     * @return the element at the top of the queue
     */
    E top(); // O(1)

    /**
     * Removes the element at the top of the queue.
     */
    void pop(); // O(logN)

    /**
     * Removes a specific element from the queue if it is present.
     *
     * @param e the element to be removed
     * @return {@code true} if the element was removed successfully, {@code false} otherwise
     */
    boolean remove(E e); // O(logN)
}
