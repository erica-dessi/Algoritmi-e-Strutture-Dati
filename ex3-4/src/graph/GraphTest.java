package graph;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import java.util.*;

/**
 * Unit tests for the {@link Graph} class.
 */
public class GraphTest {
    private Graph<String, Integer> directedGraph;
    private Graph<String, Integer> undirectedGraph;
    private Graph<String, Integer> labelledGraph;
    private Graph<String, Void> unlabelledGraph;

    /**
     * Sets up the test environment by initializing different types of graphs.
     */
    @Before
    public void setUp() {
        directedGraph = new Graph<>(true, true);
        undirectedGraph = new Graph<>(false, true);
        labelledGraph = new Graph<>(true, true);
        unlabelledGraph = new Graph<>(false, false);
    }

    /**
     * Tests the addition of nodes to the graph.
     */
    @Test
    public void testAddNode() {
        assertTrue(directedGraph.addNode("A"));
        assertTrue(directedGraph.containsNode("A"));
        assertFalse(directedGraph.addNode("A")); // Node should not be added again
    }

    /**
     * Tests adding directed edges to the graph.
     */
    @Test
    public void testAddEdgeDirected() {
        directedGraph.addNode("A");
        directedGraph.addNode("B");

        assertTrue(directedGraph.addEdge("A", "B", 5));
        assertTrue(directedGraph.containsEdge("A", "B"));
        assertFalse(directedGraph.containsEdge("B", "A")); // Directed edge should not be reciprocal
    }

    /**
     * Tests adding undirected edges to the graph.
     */
    @Test
    public void testAddEdgeUndirected() {
        undirectedGraph.addNode("A");
        undirectedGraph.addNode("B");

        assertTrue(undirectedGraph.addEdge("A", "B", 5));
        assertTrue(undirectedGraph.containsEdge("A", "B"));
        assertTrue(undirectedGraph.containsEdge("B", "A")); // Undirected edge should be reciprocal
    }

    /**
     * Tests removing nodes from the graph and ensures edges connected to the node are also removed.
     */
    @Test
    public void testRemoveNode() {
        directedGraph.addNode("A");
        directedGraph.addNode("B");
        directedGraph.addEdge("A", "B", 5);

        assertTrue(directedGraph.containsNode("A"));
        assertTrue(directedGraph.removeNode("A"));
        assertFalse(directedGraph.containsNode("A"));
        assertFalse(directedGraph.containsEdge("A", "B")); // Edge should be removed when node is removed
    }

    /**
     * Tests removing edges from the graph.
     */
    @Test
    public void testRemoveEdge() {
        directedGraph.addNode("A");
        directedGraph.addNode("B");
        directedGraph.addEdge("A", "B", 5);

        assertTrue(directedGraph.containsEdge("A", "B"));
        assertTrue(directedGraph.removeEdge("A", "B"));
        assertFalse(directedGraph.containsEdge("A", "B")); // Edge should be removed
    }

    /**
     * Tests the methods for retrieving the number of nodes and edges in the graph.
     */
    @Test
    public void testNumNodesAndEdges() {
        labelledGraph.addNode("A");
        labelledGraph.addNode("B");
        labelledGraph.addNode("C");
        labelledGraph.addEdge("A", "B", 1);
        labelledGraph.addEdge("B", "C", 2);

        assertEquals(3, labelledGraph.numNodes());
        assertEquals(2, labelledGraph.numEdges());
    }

    /**
     * Tests retrieving the neighbors of a given node.
     */
    @Test
    public void testGetNeighbours() {
        undirectedGraph.addNode("A");
        undirectedGraph.addNode("B");
        undirectedGraph.addNode("C");
        undirectedGraph.addEdge("A", "B", 1);
        undirectedGraph.addEdge("A", "C", 2);

        Collection<String> neighbours = undirectedGraph.getNeighbours("A");
        assertTrue(neighbours.contains("B"));
        assertTrue(neighbours.contains("C"));
        assertEquals(2, neighbours.size());
    }

    /**
     * Tests retrieving the label of an edge between two nodes.
     */
    @Test
    public void testGetLabel() {
        labelledGraph.addNode("A");
        labelledGraph.addNode("B");
        labelledGraph.addEdge("A", "B", 10);

        assertEquals(Integer.valueOf(10), labelledGraph.getLabel("A", "B"));
        assertNull(labelledGraph.getLabel("B", "A")); // Directed edge should not have reverse label
    }

    /**
     * Tests the behavior of unlabelled graphs where edges do not have labels.
     */
    @Test
    public void testUnlabelledGraph() {
        unlabelledGraph.addNode("A");
        unlabelledGraph.addNode("B");
        unlabelledGraph.addEdge("A", "B", null);

        assertTrue(unlabelledGraph.containsEdge("A", "B"));
        assertTrue(unlabelledGraph.containsEdge("B", "A")); // Undirected edge should be reciprocal
        assertNull(unlabelledGraph.getLabel("A", "B")); // No label should be associated with the edge
    }
}
