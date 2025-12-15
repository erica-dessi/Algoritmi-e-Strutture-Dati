package graph;

import java.util.*;
import graph.AbstractGraph;
import graph.Edge;


/**
 * Represents a graph with vertices and edges.
 *
 * @param <V> the type of the vertices in the graph
 * @param <L> the type of the label associated with the edges
 */
public class Graph<V, L> implements AbstractGraph<V, L> {
    private final Map<V, List<Edge<V, L>>> adjacencyList;
    private final boolean directed;
    private final boolean labelled;

    /**
     * Constructs a graph with specified properties.
     *
     * @param directed whether the graph is directed
     * @param labelled whether the graph's edges are labelled
     */
    public Graph(boolean directed, boolean labelled) {
        this.adjacencyList = new HashMap<>();
        this.directed = directed;
        this.labelled = labelled;
    }

    /**
     * Returns whether the graph is directed.
     *
     * @return true if the graph is directed, false otherwise
     */
    @Override
    public boolean isDirected() {
        return directed;
    }

    /**
     * Returns whether the graph's edges are labelled.
     *
     * @return true if the graph is labelled, false otherwise
     */
    @Override
    public boolean isLabelled() {
        return labelled;
    }

    /**
     * Adds a node to the graph.
     *
     * @param a the node to be added
     * @return true if the node was successfully added, false if the node already exists
     */
    @Override
    public boolean addNode(V a) {
        if (adjacencyList.containsKey(a)) {
            return false;
        }
        adjacencyList.put(a, new ArrayList<>());
        return true;
    }

    /**
     * Adds an edge between two nodes in the graph with a label.
     *
     * @param a the start node
     * @param b the end node
     * @param l the label of the edge
     * @return true if the edge was successfully added, false if the edge already exists
     */
    @Override
    public boolean addEdge(V a, V b, L l) {
        if (!adjacencyList.containsKey(a) || !adjacencyList.containsKey(b)) {
            return false;
        }
        Edge<V, L> edge = new Edge<>(a, b, l);
        if (adjacencyList.get(a).contains(edge)) {
            return false;
        }
        adjacencyList.get(a).add(edge);
        if (!directed) {
            Edge<V, L> reverseEdge = new Edge<>(b, a, l);
            adjacencyList.get(b).add(reverseEdge);
        }
        return true;
    }

    /**
     * Checks if a node is in the graph.
     *
     * @param a the node to check
     * @return true if the node is in the graph, false otherwise
     */
    @Override
    public boolean containsNode(V a) {
        return adjacencyList.containsKey(a);
    }

    /**
     * Checks if there is an edge between two nodes in the graph.
     *
     * @param a the start node
     * @param b the end node
     * @return true if there is an edge from node a to node b, false otherwise
     */
    @Override
    public boolean containsEdge(V a, V b) {
        if (!adjacencyList.containsKey(a)) {
            return false;
        }
        return adjacencyList.get(a).stream().anyMatch(e -> e.getEnd().equals(b));
    }

    /**
     * Removes a node from the graph.
     *
     * @param a the node to be removed
     * @return true if the node was successfully removed, false if the node does not exist
     */
    @Override
    public boolean removeNode(V a) {
        if (!adjacencyList.containsKey(a)) {
            return false;
        }
        adjacencyList.remove(a);
        for (V node : adjacencyList.keySet()) {
            adjacencyList.get(node).removeIf(edge -> edge.getEnd().equals(a));
        }
        return true;
    }

    /**
     * Removes an edge between two nodes from the graph.
     *
     * @param a the start node
     * @param b the end node
     * @return true if the edge was successfully removed, false if no such edge exists
     */
    @Override
    public boolean removeEdge(V a, V b) {
        if (!adjacencyList.containsKey(a)) {
            return false;
        }
        boolean removed = adjacencyList.get(a).removeIf(edge -> edge.getEnd().equals(b));
        if (!directed && adjacencyList.containsKey(b)) {
            adjacencyList.get(b).removeIf(edge -> edge.getEnd().equals(a));
        }
        return removed;
    }

    /**
     * Returns the number of nodes in the graph.
     *
     * @return the number of nodes
     */
    @Override
    public int numNodes() {
        return adjacencyList.size();
    }

    /**
     * Returns the number of edges in the graph.
     *
     * @return the number of edges
     */
    @Override
    public int numEdges() {
        int count = 0;
        for (List<Edge<V, L>> edges : adjacencyList.values()) {
            count += edges.size();
        }
        return directed ? count : count / 2;
    }

    /**
     * Returns a collection of all nodes in the graph.
     *
     * @return a collection of nodes
     */
    @Override
    public Collection<V> getNodes() {
        return adjacencyList.keySet();
    }

    /**
     * Returns a collection of all edges in the graph.
     *
     * @return a collection of edges
     */
    @Override
    public Collection<Edge<V, L>> getEdges() {
        List<Edge<V, L>> edges = new ArrayList<>();
        for (List<Edge<V, L>> edgeList : adjacencyList.values()) {
            edges.addAll(edgeList);
        }
        return edges;
    }

    /**
     * Returns a collection of the neighbors of a given node.
     *
     * @param a the node for which to find neighbors
     * @return a collection of neighboring nodes
     */
    @Override
    public Collection<V> getNeighbours(V a) {
        if (!adjacencyList.containsKey(a)) {
            return Collections.emptyList();
        }
        List<V> neighbours = new ArrayList<>();
        for (Edge<V, L> edge : adjacencyList.get(a)) {
            neighbours.add(edge.getEnd());
        }
        return neighbours;
    }

    /**
     * Returns the label associated with the edge between two nodes.
     *
     * @param a the start node
     * @param b the end node
     * @return the label of the edge, or null if no such edge exists
     */
    @Override
    public L getLabel(V a, V b) {
        if (!adjacencyList.containsKey(a)) {
            return null;
        }
        for (Edge<V, L> edge : adjacencyList.get(a)) {
            if (edge.getEnd().equals(b)) {
                return edge.getLabel();
            }
        }
        return null;
    }
}
