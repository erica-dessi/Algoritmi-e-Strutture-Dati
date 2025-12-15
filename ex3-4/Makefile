# Variables for commands and options
JAVAC = javac
JAVA = java
JUNIT_JAR = junit-4.12.jar
HAMCREST_JAR = hamcrest-core-1.3.jar
CLASSES_DIR = classes

# Compile all classes
all: $(CLASSES_DIR)/priorityqueue/PriorityQueueTests.class $(CLASSES_DIR)/graph/Graph.class $(CLASSES_DIR)/graph/AbstractEdge.class $(CLASSES_DIR)/graph/Prim.class $(CLASSES_DIR)/graphusage/GraphUsage.class $(CLASSES_DIR)/graph/GraphTest.class $(CLASSES_DIR)/graph/GraphTestRunner.class

# Rule to compile EX3
ex3: $(CLASSES_DIR)/priorityqueue/PriorityQueueTests.class
	$(JAVA) -cp $(CLASSES_DIR):$(JUNIT_JAR):$(HAMCREST_JAR) org.junit.runner.JUnitCore priorityqueue.PriorityQueueTests

# Rule to compile EX4
ex4: $(CLASSES_DIR)/graph/Graph.class $(CLASSES_DIR)/graph/AbstractEdge.class $(CLASSES_DIR)/graph/Prim.class $(CLASSES_DIR)/graphusage/GraphUsage.class $(CLASSES_DIR)/graph/GraphTest.class $(CLASSES_DIR)/graph/GraphTestRunner.class
	$(JAVA) -cp $(CLASSES_DIR) graphusage.GraphUsage "../italian_dist_graph.csv" "../output_graph.csv"
	$(JAVA) -cp $(CLASSES_DIR):$(JUNIT_JAR):$(HAMCREST_JAR) graph.GraphTestRunner

# Rule to compile AbstractEdge first
$(CLASSES_DIR)/graph/AbstractEdge.class: src/graph/AbstractEdge.java
	$(JAVAC) -d $(CLASSES_DIR) src/graph/AbstractEdge.java

# Rule to compile AbstractGraph after AbstractEdge
$(CLASSES_DIR)/graph/AbstractGraph.class: $(CLASSES_DIR)/graph/AbstractEdge.class src/graph/AbstractGraph.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR) src/graph/AbstractGraph.java

# Rule to compile Edge before Graph
$(CLASSES_DIR)/graph/Edge.class: src/graph/Edge.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR) src/graph/Edge.java

# Rule to compile Prim.java
$(CLASSES_DIR)/graph/Prim.class: src/graph/Prim.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR) src/graph/Prim.java

# Rule to compile Graph.java after AbstractGraph, AbstractEdge, and Edge
$(CLASSES_DIR)/graph/Graph.class: $(CLASSES_DIR)/graph/AbstractGraph.class $(CLASSES_DIR)/graph/AbstractEdge.class $(CLASSES_DIR)/graph/Edge.class
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR) src/graph/Graph.java

# Rule to compile GraphUsage
$(CLASSES_DIR)/graphusage/GraphUsage.class: src/graphusage/GraphUsage.java $(CLASSES_DIR)/graph/Graph.class $(CLASSES_DIR)/graph/AbstractGraph.class $(CLASSES_DIR)/graph/AbstractEdge.class $(CLASSES_DIR)/graph/Prim.class
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR) src/graphusage/GraphUsage.java

# Rule to compile PriorityQueueTests
$(CLASSES_DIR)/priorityqueue/PriorityQueueTests.class: src/priorityqueue/*.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(JUNIT_JAR):$(HAMCREST_JAR) src/priorityqueue/*.java

# Rule to compile GraphTest
$(CLASSES_DIR)/graph/GraphTest.class: src/graph/GraphTest.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR):$(JUNIT_JAR) src/graph/GraphTest.java

# Rule to compile GraphTestRunner
$(CLASSES_DIR)/graph/GraphTestRunner.class: src/graph/GraphTestRunner.java
	$(JAVAC) -d $(CLASSES_DIR) -cp $(CLASSES_DIR):$(JUNIT_JAR) src/graph/GraphTestRunner.java

# Rule to clean compiled files
clean:
	rm -f $(CLASSES_DIR)/priorityqueue/*.class $(CLASSES_DIR)/graph/*.class $(CLASSES_DIR)/graphusage/*.class

# Rule to run all tests
test: $(CLASSES_DIR)/priorityqueue/PriorityQueueTests.class $(CLASSES_DIR)/graph/GraphTest.class $(CLASSES_DIR)/graph/GraphTestRunner.class
	$(JAVA) -cp $(CLASSES_DIR):$(JUNIT_JAR):$(HAMCREST_JAR) org.junit.runner.JUnitCore priorityqueue.PriorityQueueTests
	$(JAVA) -cp $(CLASSES_DIR):$(JUNIT_JAR):$(HAMCREST_JAR) graph.GraphTestRunner

# Rule to run main program
main: $(CLASSES_DIR)/graphusage/GraphUsage.class
	$(JAVA) -cp $(CLASSES_DIR) graphusage.GraphUsage "../italian_dist_graph.csv" "../output_graph.csv"
