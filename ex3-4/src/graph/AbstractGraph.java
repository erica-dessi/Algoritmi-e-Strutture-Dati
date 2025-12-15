package graph;

import java.util.Collection;

/**
 * Represents a graph with vertices and edges.
 *
 * @param <V> the type of the vertices in the graph
 * @param <L> the type of the label associated with the edges
 */
public interface AbstractGraph<V, L> {

    /**
     * Checks if the graph is directed.
     *
     * @return true if the graph is directed, false otherwise
     */
    public boolean isDirected();

    /**
     * Checks if the graph has labels on its edges.
     *
     * @return true if the graph is labelled, false otherwise
     */
    public boolean isLabelled();

    /**
     * Adds a node to the graph.
     *
     * @param a the node to be added
     * @return true if the node was successfully added, false otherwise
     */
    public boolean addNode(V a);

    /**
     * Adds an edge between two nodes in the graph with a label.
     *
     * @param a the start node
     * @param b the end node
     * @param l the label of the edge
     * @return true if the edge was successfully added, false otherwise
     */
    public boolean addEdge(V a, V b, L l);

    /**
     * Checks if a node is in the graph.
     *
     * @param a the node to check
     * @return true if the node is in the graph, false otherwise
     */
    public boolean containsNode(V a);

    /**
     * Checks if there is an edge between two nodes in the graph.
     *
     * @param a the start node
     * @param b the end node
     * @return true if there is an edge between the nodes, false otherwise
     */
    public boolean containsEdge(V a, V b);

    /**
     * Removes a node from the graph.
     *
     * @param a the node to be removed
     * @return true if the node was successfully removed, false otherwise
     */
    public boolean removeNode(V a);

    /**
     * Removes an edge between two nodes from the graph.
     *
     * @param a the start node
     * @param b the end node
     * @return true if the edge was successfully removed, false otherwise
     */
    public boolean removeEdge(V a, V b);

    /**
     * Returns the number of nodes in the graph.
     *
     * @return the number of nodes
     */
    public int numNodes();

    /**
     * Returns the number of edges in the graph.
     *
     * @return the number of edges
     */
    public int numEdges();

    /**
     * Returns a collection of all nodes in the graph.
     *
     * @return a collection of nodes
     */
    public Collection<V> getNodes();

    /**
     * Returns a collection of all edges in the graph.
     *
     * @return a collection of edges
     */
    public Collection<? extends AbstractEdge<V, L>> getEdges();

    /**
     * Returns a collection of the neighbors of a given node.
     *
     * @param a the node for which to find neighbors
     * @return a collection of neighboring nodes
     */
    public Collection<V> getNeighbours(V a);

    /**
     * Returns the label associated with the edge between two nodes.
     *
     * @param a the start node
     * @param b the end node
     * @return the label of the edge, or null if no such edge exists
     */
    public L getLabel(V a, V b);
}
