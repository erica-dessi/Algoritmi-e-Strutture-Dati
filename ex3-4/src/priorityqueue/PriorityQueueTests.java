package priorityqueue;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.Comparator;
import org.junit.Before;
import org.junit.Test;

/**
 * Unit tests for the {@link PriorityQueue} class.
 */
public class PriorityQueueTests {

    /**
     * Comparator for {@link Integer} elements.
     */
    class IntegerComparator implements Comparator<Integer> {
        @Override
        public int compare(Integer x, Integer y) {
            return x.compareTo(y);
        }
    }

    /**
     * Comparator for {@link Double} elements.
     */
    class DoubleComparator implements Comparator<Double> {
        @Override
        public int compare(Double x, Double y) {
            return x.compareTo(y);
        }
    }

    /**
     * Comparator for {@link String} elements.
     */
    class StringComparator implements Comparator<String> {
        @Override
        public int compare(String x, String y) {
            return x.compareTo(y);
        }
    }

    private Integer int1, int2, int3;
    private Double doub1, doub2, doub3;
    private String str1, str2, str3;
    private PriorityQueue<Integer> PriorityQueueInt;
    private PriorityQueue<Double> PriorityQueueDoub;
    private PriorityQueue<String> PriorityQueueStr;

    /**
     * Sets up the test environment by initializing the priority queues and test elements.
     */
    @Before
    public void setUp() {
        int1 = -12;
        int2 = 0;
        int3 = 4;
        doub1 = 34.55;
        doub2 = -454.91;
        doub3 = 1.6;
        str1 = "Cane";
        str2 = "Gatto";
        str3 = "Pappagallo";
        PriorityQueueInt = new PriorityQueue<>(new IntegerComparator());
        PriorityQueueDoub = new PriorityQueue<>(new DoubleComparator());
        PriorityQueueStr = new PriorityQueue<>(new StringComparator());
    }

    /**
     * Tests whether the priority queue is empty initially.
     */
    @Test
    public void testIsEmpty_zeroEl() {
        assertTrue(PriorityQueueInt.empty());
        assertTrue(PriorityQueueDoub.empty());
        assertTrue(PriorityQueueStr.empty());
    }

    /**
     * Tests whether the priority queue is not empty after adding one element.
     */
    @Test
    public void testIsEmpty_OneEl() {
        PriorityQueueInt.push(int1);
        PriorityQueueDoub.push(doub1);
        PriorityQueueStr.push(str1);
        assertFalse(PriorityQueueInt.empty());
        assertFalse(PriorityQueueDoub.empty());
        assertFalse(PriorityQueueStr.empty());
    }

    /**
     * Tests adding an {@link Integer} element to the priority queue.
     */
    @Test
    public void testPushInteger() {
        PriorityQueueInt.push(int1);
        assertFalse(PriorityQueueInt.empty());
    }

    /**
     * Tests adding a {@link Double} element to the priority queue.
     */
    @Test
    public void testPushDouble() {
        PriorityQueueDoub.push(doub1);
        assertFalse(PriorityQueueDoub.empty());
    }

    /**
     * Tests adding a {@link String} element to the priority queue.
     */
    @Test
    public void testPushString() {
        PriorityQueueStr.push(str1);
        assertFalse(PriorityQueueStr.empty());
    }

    /**
     * Tests whether an {@link Integer} element is contained in the priority queue.
     */
    @Test
    public void testContainsInteger() {
        PriorityQueueInt.push(int1);
        assertTrue(PriorityQueueInt.contains(int1));
    }

    /**
     * Tests whether a {@link Double} element is contained in the priority queue.
     */
    @Test
    public void testContainsDouble() {
        PriorityQueueDoub.push(doub1);
        assertTrue(PriorityQueueDoub.contains(doub1));
    }

    /**
     * Tests whether a {@link String} element is contained in the priority queue.
     */
    @Test
    public void testContainsString() {
        PriorityQueueStr.push(str1);
        assertTrue(PriorityQueueStr.contains(str1));
    }

    /**
     * Tests retrieving the top {@link Integer} element from the priority queue.
     */
    @Test
    public void testTopInteger() {
        PriorityQueueInt.push(int1);
        assertEquals(int1, PriorityQueueInt.top());
    }

    /**
     * Tests retrieving the top {@link Double} element from the priority queue.
     */
    @Test
    public void testTopDouble() {
        PriorityQueueDoub.push(doub1);
        assertEquals(doub1, PriorityQueueDoub.top());
    }

    /**
     * Tests retrieving the top {@link String} element from the priority queue.
     */
    @Test
    public void testTopString() {
        PriorityQueueStr.push(str1);
        assertEquals(str1, PriorityQueueStr.top());
    }

    /**
     * Tests removing the top {@link Integer} element from the priority queue.
     */
    @Test
    public void testPopInteger() {
        PriorityQueueInt.push(int1);
        PriorityQueueInt.pop();
        assertTrue(PriorityQueueInt.empty());
    }

    /**
     * Tests removing the top {@link Double} element from the priority queue.
     */
    @Test
    public void testPopDouble() {
        PriorityQueueDoub.push(doub1);
        PriorityQueueDoub.pop();
        assertTrue(PriorityQueueDoub.empty());
    }

    /**
     * Tests removing the top {@link String} element from the priority queue.
     */
    @Test
    public void testPopString() {
        PriorityQueueStr.push(str1);
        PriorityQueueStr.pop();
        assertTrue(PriorityQueueStr.empty());
    }

    /**
     * Tests removing a specific {@link Integer} element from the priority queue.
     */
    @Test
    public void testRemoveInteger() {
        PriorityQueueInt.push(int1);
        assertTrue(PriorityQueueInt.remove(int1));
        assertTrue(PriorityQueueInt.empty());
    }

    /**
     * Tests removing a specific {@link Double} element from the priority queue.
     */
    @Test
    public void testRemoveDouble() {
        PriorityQueueDoub.push(doub1);
        assertTrue(PriorityQueueDoub.remove(doub1));
        assertTrue(PriorityQueueDoub.empty());
    }

    /**
     * Tests removing a specific {@link String} element from the priority queue.
     */
    @Test
    public void testRemoveString() {
        PriorityQueueStr.push(str1);
        assertTrue(PriorityQueueStr.remove(str1));
        assertTrue(PriorityQueueStr.empty());
    }
}
