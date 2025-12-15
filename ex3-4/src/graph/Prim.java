package graph;

import priorityqueue.PriorityQueue;
import java.util.Collection;
import java.util.HashSet;
import java.util.Set;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * Provides an implementation of Prim's algorithm for finding the Minimum Spanning Tree (MST) of a graph.
 */
public class Prim {

    /**
     * Adds edges from a specified node to the priority queue if they connect to nodes not yet included in the MST.
     *
     * @param <V> the type of vertices in the graph
     * @param <L> the type of the label of the edges, which must extend Number
     * @param graph the graph from which edges are extracted
     * @param includedNodes the set of nodes already included in the MST
     * @param edgeQueue the priority queue to which edges are added
     * @param node the node whose edges are to be added
     */
    private static <V, L extends Number> void addEdgesFromNode(Graph<V, L> graph, Set<V> includedNodes, PriorityQueue<AbstractEdge<V, L>> edgeQueue, V node) {
        for (AbstractEdge<V, L> edge : graph.getEdges()) {
            if (edge.getStart().equals(node) && !includedNodes.contains(edge.getEnd())) {
                edgeQueue.push(edge);
            }
        }
    }

    /**
     * Computes the Minimum Spanning Forest (MSF) of a graph using Prim's algorithm.
     * The graph is assumed to be connected. If it is not connected, the result will be a forest (collection of MSTs).
     *
     * @param <V> the type of vertices in the graph
     * @param <L> the type of the label of the edges, which must extend Number
     * @param graph the graph from which the MSF is computed
     * @return a collection of edges that form the Minimum Spanning Forest
     */
    public static <V, L extends Number> Collection<? extends AbstractEdge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        List<AbstractEdge<V, L>> mstEdges = new ArrayList<>();
        Set<V> includedNodes = new HashSet<>();
        PriorityQueue<AbstractEdge<V, L>> edgeQueue = new PriorityQueue<>(Comparator.comparingDouble(e -> e.getLabel().doubleValue()));

        // Start from an arbitrary node
        V startNode = graph.getNodes().iterator().next();
        includedNodes.add(startNode);
        addEdgesFromNode(graph, includedNodes, edgeQueue, startNode);

        // Process edges to form the MST
        while (!edgeQueue.empty()) {
            AbstractEdge<V, L> minEdge = edgeQueue.top();
            edgeQueue.pop();

            V start = minEdge.getStart();
            V end = minEdge.getEnd();

            // Skip edges that would form a cycle
            if (includedNodes.contains(start) && includedNodes.contains(end)) {
                continue;
            }

            mstEdges.add(minEdge);

            // Add the newly included node and its edges to the priority queue
            V newNode = includedNodes.contains(start) ? end : start;
            includedNodes.add(newNode);
            addEdgesFromNode(graph, includedNodes, edgeQueue, newNode);
        }

        return mstEdges;
    }
}
