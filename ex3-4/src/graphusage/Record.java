package graphusage;

/**
 * Represents a record containing information about an edge in a graph.
 * This includes the starting node, the ending node, and the distance (weight) of the edge.
 */
class Record {
    private final String from;
    private final String to;
    private final Double distance;

    /**
     * Constructs a new {@code Record} with the specified start node, end node, and distance.
     *
     * @param from     the starting node of the edge
     * @param to       the ending node of the edge
     * @param distance the distance (weight) of the edge
     */
    public Record(String from, String to, Double distance) {
        this.from = from;
        this.to = to;
        this.distance = distance;
    }

    /**
     * Returns the starting node of the edge.
     *
     * @return the starting node
     */
    public String getFrom() {
        return this.from;
    }

    /**
     * Returns the ending node of the edge.
     *
     * @return the ending node
     */
    public String getTo() {
        return this.to;
    }

    /**
     * Returns the distance (weight) of the edge.
     *
     * @return the distance of the edge
     */
    public Double getDistance() {
        return this.distance;
    }
}
