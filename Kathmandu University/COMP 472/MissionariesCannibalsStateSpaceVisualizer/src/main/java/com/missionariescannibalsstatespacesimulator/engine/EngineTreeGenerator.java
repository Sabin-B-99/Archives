package com.missionariescannibalsstatespacesimulator.engine;

public class EngineTreeGenerator {

    public static void generateStateSpaceTree(StateNode rootNode){
        StateNode currentNode = null;
        if(rootNode != null){
            rootNode.generateChildNodes();
            for (int i = 0; i < rootNode.getChildren().size(); i++) {
                currentNode = rootNode.getChildren().get(i);
                generateStateSpaceTree(currentNode);
            }
        }
    }

    public static void printChildState(StateNode rootNode){
        if(rootNode != null){
            int nodeLevel = 0;
            nodeLevel = rootNode.getLevel();
            String spacesForLevel = getSpace(nodeLevel * 3);
            String prefix = spacesForLevel + "|__";
            System.out.println(prefix + rootNode.toString());
            for (StateNode childNode: rootNode.getChildren()) {
                printChildState(childNode);
            }
        }
    }

    private static String getSpace(int numberOfSpace){
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < numberOfSpace; i++) {
            builder.append(' ');
        }
        return builder.toString();
    }
}
