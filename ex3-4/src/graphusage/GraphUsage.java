package graphusage;

import graph.Graph;
import graph.AbstractEdge;
import graph.Prim;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * A utility class for reading a graph from a CSV file, computing its Minimum Spanning Forest using Prim's algorithm,
 * and writing the result to an output CSV file.
 */
public class GraphUsage {

    /**
     * The main method that orchestrates the graph processing. It reads a graph from the input CSV file, computes
     * the Minimum Spanning Forest (MSF), and writes the result to the output CSV file.
     *
     * @param args command-line arguments: <input_csv> and <output_csv>
     */
    public static void main(String[] args) {
        if (args.length < 2) {
            System.err.println("Usage: java graphusage.GraphUsage <input_csv> <output_csv>");
            return;
        }

        String inputFilePath = args[0];
        String outputFilePath = args[1];

        // Create an undirected and labeled graph
        Graph<String, Double> graph = new Graph<>(false, true);

        // Read the CSV file and populate the graph
        try (Scanner scanner = new Scanner(new File(inputFilePath))) {
            while (scanner.hasNextLine()) {
                String[] line = scanner.nextLine().split(",");
                if (line.length == 3) {
                    String from = line[0].trim();
                    String to = line[1].trim();
                    Double distance = Double.parseDouble(line[2].trim());

                    // Add nodes and edge to the graph
                    graph.addNode(from);
                    graph.addNode(to);
                    graph.addEdge(from, to, distance);

                    // Add the edge in the opposite direction if the graph is undirected
                    if (!graph.isDirected()) {
                        graph.addEdge(to, from, distance);
                    }
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error: File not found.");
            e.printStackTrace();
            return;
        } catch (NumberFormatException e) {
            System.err.println("Error: Incorrect number format in CSV file.");
            e.printStackTrace();
            return;
        }

        // Calculate the Minimum Spanning Forest using Prim's algorithm
        Collection<? extends AbstractEdge<String, Double>> mstEdges = Prim.minimumSpanningForest(graph);

        // Collect nodes included in the Minimum Spanning Forest
        Set<String> nodesInMST = new HashSet<>();
        double totalWeight = 0.0;

        // Write the result to the output CSV file
        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath))) {
            for (AbstractEdge<String, Double> edge : mstEdges) {
                nodesInMST.add(edge.getStart());
                nodesInMST.add(edge.getEnd());
                totalWeight += edge.getLabel();
                writer.printf("%s,%s,%.3f%n", edge.getStart(), edge.getEnd(), edge.getLabel());
            }
            
            // Print the final statistics to System.err
            System.err.printf("Minimum Spanning Forest generated with %d nodes, %d edges, and a total weight of %.3f km%n",
                              nodesInMST.size(), mstEdges.size(), totalWeight / 1000);
        } catch (IOException e) {
            System.err.println("Error: Unable to write to output file.");
            e.printStackTrace();
        }
    }
}
