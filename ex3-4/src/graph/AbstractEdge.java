package graph;

/**
 * Represents an edge in a graph with a start vertex, an end vertex, and a label.
 *
 * @param <V> the type of the vertices in the graph
 * @param <L> the type of the label associated with the edge
 */
public interface AbstractEdge<V, L> {

    /**
     * Returns the start vertex of the edge.
     *
     * @return the start vertex
     */
    public V getStart();

    /**
     * Returns the end vertex of the edge.
     *
     * @return the end vertex
     */
    public V getEnd();

    /**
     * Returns the label associated with the edge.
     *
     * @return the label
     */
    public L getLabel();
}
