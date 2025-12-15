package graph;

/**
 * Represents an edge in a graph with a start vertex, an end vertex, and a label.
 *
 * @param <V> the type of the vertices
 * @param <L> the type of the label associated with the edge
 */
public class Edge<V, L> implements AbstractEdge<V, L> {
    private final V start;
    private final V end;
    private final L label;

    /**
     * Constructs an Edge with the specified start vertex, end vertex, and label.
     *
     * @param start the start vertex of the edge
     * @param end the end vertex of the edge
     * @param label the label associated with the edge
     */
    public Edge(V start, V end, L label) {
        this.start = start;
        this.end = end;
        this.label = label;
    }

    /**
     * Returns the start vertex of the edge.
     *
     * @return the start vertex
     */
    @Override
    public V getStart() {
        return start;
    }

    /**
     * Returns the end vertex of the edge.
     *
     * @return the end vertex
     */
    @Override
    public V getEnd() {
        return end;
    }

    /**
     * Returns the label associated with the edge.
     *
     * @return the label
     */
    @Override
    public L getLabel() {
        return label;
    }

    /**
     * Indicates whether some other object is "equal to" this edge.
     * Two edges are considered equal if they have the same start and end vertices.
     *
     * @param o the reference object with which to compare
     * @return true if this edge is equal to the other object, false otherwise
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Edge<?, ?> edge = (Edge<?, ?>) o;

        if (!start.equals(edge.start)) return false;
        return end.equals(edge.end);
    }

    /**
     * Returns a hash code value for the edge. The hash code is computed using the start and end vertices.
     *
     * @return a hash code value for this edge
     */
    @Override
    public int hashCode() {
        int result = start.hashCode();
        result = 31 * result + end.hashCode();
        return result;
    }

    /**
     * Returns a string representation of the edge.
     * The string includes the start vertex, end vertex, and label.
     *
     * @return a string representation of the edge
     */
    @Override
    public String toString() {
        return "Edge{" +
                "start=" + start +
                ", end=" + end +
                ", label=" + label +
                '}';
    }
}
