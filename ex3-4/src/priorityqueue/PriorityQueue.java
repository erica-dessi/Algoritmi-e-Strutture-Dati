package priorityqueue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * A priority queue implementation using a binary heap.
 *
 * @param <E> the type of elements in the queue
 */
public class PriorityQueue<E> implements AbstractQueue<E> {
    private ArrayList<E> queue;
    private HashMap<E, Integer> hashMap;
    private Comparator<E> comparator;

    /**
     * Constructs a new {@code PriorityQueue} with the specified comparator.
     *
     * @param comparator the comparator to determine the order of elements in the queue
     */
    public PriorityQueue(Comparator<E> comparator) {
        this.queue = new ArrayList<>();
        this.hashMap = new HashMap<>();
        this.comparator = comparator;
    }

    /**
     * Checks if the queue is empty.
     *
     * @return {@code true} if the queue is empty, {@code false} otherwise
     */
    @Override
    public boolean empty() {
        return queue.isEmpty();
    }

    /**
     * Adds an element to the queue. If the element is already in the queue, it is not added again.
     *
     * @param e the element to be added
     * @return {@code true} if the element was added successfully, {@code false} otherwise
     */
    @Override
    public boolean push(E e) {
        if (contains(e)) {
            return false;
        } else {
            queue.add(e);
            int index = queue.size() - 1;
            hashMap.put(e, index);
            fixQueue(index);
            return true;
        }
    }

    /**
     * Checks if the queue contains a specific element.
     *
     * @param e the element to check
     * @return {@code true} if the element is in the queue, {@code false} otherwise
     */
    @Override
    public boolean contains(E e) {
        return hashMap.containsKey(e);
    }

    /**
     * Retrieves the element at the top of the queue without removing it.
     *
     * @return the element at the top of the queue
     * @throws IllegalStateException if the queue is empty
     */
    @Override
    public E top() {
        if (empty()) {
            throw new IllegalStateException("Queue is empty.");
        }
        return queue.get(0);
    }

    /**
     * Removes the element at the top of the queue.
     *
     * @throws IllegalStateException if the queue is empty
     */
    @Override
    public void pop() {
        if (empty()) {
            throw new IllegalStateException("Queue is empty.");
        }
        int last = queue.size() - 1;
        swap(0, last);
        hashMap.remove(queue.get(last));
        queue.remove(last);
        fixQueue(0);
    }

    /**
     * Removes a specific element from the queue if it is present.
     *
     * @param e the element to be removed
     * @return {@code true} if the element was removed successfully, {@code false} otherwise
     */
    @Override
    public boolean remove(E e) {
        Integer index = hashMap.get(e);
        int last = queue.size() - 1;
        if (index == null) {
            return false;
        } else {
            if (index != last) {
                swap(index, last);
                queue.remove(last); // Remove the last element
                hashMap.remove(e);  // Remove it from the map
                fixQueue(index);
            } else {
                queue.remove(last); // If it's the last element we remove it
                hashMap.remove(e);  // Remove it from the map
            }
            return true;
        }
    }

    /**
     * Reorders the queue to maintain heap properties after an element has been added or removed.
     *
     * @param index the index of the element to be reordered
     */
    private void fixQueue(int index) {
        // Move the new element up to the correct position
        int parent = (index - 1) / 2;

        while (index > 0 && compare(queue.get(index), queue.get(parent)) < 0) {
            swap(index, parent); // Swap if the element is smaller than its parent
            index = parent;
            parent = (index - 1) / 2; // Update the parent index
        }

        // Move a displaced element down to the correct position
        int size = queue.size();
        boolean loop = true;

        while (index < size && loop) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallestChild = index;

            if (leftChild < size && compare(queue.get(leftChild), queue.get(smallestChild)) < 0) {
                smallestChild = leftChild;
            }

            if (rightChild < size && compare(queue.get(rightChild), queue.get(smallestChild)) < 0) {
                smallestChild = rightChild;
            }

            if (smallestChild == index) {
                loop = false; // Stop if the element is in the correct position
            }

            swap(index, smallestChild); // Swap and continue downward
            index = smallestChild;
        }
    }

    /**
     * Swaps two elements in the queue and updates their indices in the hash map.
     *
     * @param i the index of the first element
     * @param j the index of the second element
     */
    private void swap(int i, int j) {
        E temp_i = queue.get(i);
        E temp_j = queue.get(j);
        queue.set(i, temp_j);
        queue.set(j, temp_i);
        hashMap.put(temp_j, i);
        hashMap.put(temp_i, j);
    }

    /**
     * Compares two elements using the specified comparator.
     *
     * @param e1 the first element to be compared
     * @param e2 the second element to be compared
     * @return a negative integer, zero, or a positive integer as the first element
     *         is less than, equal to, or greater than the second element
     * @throws IllegalStateException if the comparator is {@code null}
     */
    private int compare(E e1, E e2) {
        if (comparator != null) {
            return comparator.compare(e1, e2);
        } else {
            throw new IllegalStateException("Comparator cannot be null.");
        }
    }
}
