package com.badalsabin.ai.eightpuzzlebfsdfs.engine;

import java.util.*;

public class StateTreeManager {
    private final HashSet<StateTreeNode> exploredNodes = new HashSet<>();

    private static final int STATE_LIMIT = 5000;
    public boolean puzzleSolved;
    public boolean dfsStateLimitReached;
    public boolean bfsStateLimitReached;

    private StateTreeNode finalState;

    private String stateReachingPath;

    public StateTreeManager(StateTreeNode finalState) {
        this.finalState = finalState;
        this.puzzleSolved = false;
        this.dfsStateLimitReached = false;
        this.bfsStateLimitReached = false;
    }

    private void applyOperators(StateTreeNode node){
        int[] emptyRowCol  = node.getCurrentBoardState().getEmptyRowColPos();
        int[][] boardState = node.getCurrentBoardState().getState();
        if(!node.equals(finalState)){
            for (EightPuzzleOperators op: EightPuzzleOperators.values()) {
                StateTreeNode child = applyOperator(boardState, emptyRowCol, op);
                if(child != null && !exploredNodes.contains(child)){
                    child.setOperatorUsed(op.toString());
                    node.addChild(child);
                    if(child.equals(finalState)){
                        this.puzzleSolved = true;
                        child.setGoalState(true);
                        this.stateReachingPath = findStateReachingPath(child);
                    };
                    if(puzzleSolved || dfsStateLimitReached || bfsStateLimitReached) break;
                }
            }
            exploredNodes.add(node);
            dfsStateLimitReached = exploredNodes.size() > STATE_LIMIT;
            bfsStateLimitReached = exploredNodes.size() > STATE_LIMIT;
        }
    }


    private StateTreeNode applyOperator(int[][] boardStateOriginal, int[] emptyRowCol, EightPuzzleOperators operator){
        int emptyRowPos = emptyRowCol[0];
        int emptyColPos = emptyRowCol[1];

        int[][] boardState = Arrays.stream(boardStateOriginal)
                .map(int[]::clone).toArray(int[][]::new);

        try {
            if(emptyRowPos != -1 && emptyColPos != -1){
                if(operator == EightPuzzleOperators.R){
                    boardState[emptyRowPos][emptyColPos] = boardState[emptyRowPos][emptyColPos + 1];
                    boardState[emptyRowPos][emptyColPos+1] = Board.EMPTY_ROW_COL_VALUE;
                } else if (operator == EightPuzzleOperators.L) {
                    boardState[emptyRowPos][emptyColPos] = boardState[emptyRowPos][emptyColPos - 1];
                    boardState[emptyRowPos][emptyColPos - 1] = Board.EMPTY_ROW_COL_VALUE;
                } else if (operator == EightPuzzleOperators.U) {
                    boardState[emptyRowPos][emptyColPos] = boardState[emptyRowPos - 1][emptyColPos];
                    boardState[emptyRowPos - 1][emptyColPos] = Board.EMPTY_ROW_COL_VALUE;
                }else {
                    boardState[emptyRowPos][emptyColPos] = boardState[emptyRowPos + 1][emptyColPos];
                    boardState[emptyRowPos + 1][emptyColPos] = Board.EMPTY_ROW_COL_VALUE;
                }
            }
        }catch (IndexOutOfBoundsException e){
            return null;
        }
        return new StateTreeNode(new Board(boardState));
    }


    public void generateStateSpaceTreeDFS(StateTreeNode rootNode){
        StateTreeNode currentNode = null;
        if(rootNode != null){
            applyOperators(rootNode);
            for (int i = 0; i < rootNode.getChildren().size(); i++) {
                currentNode = rootNode.getChildren().get(i);
                if(!puzzleSolved && (!dfsStateLimitReached || !bfsStateLimitReached)){
                    generateStateSpaceTreeDFS(currentNode);
                }
            }
        }
    }

    public void generateStateSpaceTreeBFS(StateTreeNode rootNode){
        Queue<StateTreeNode> queue = new LinkedList<>();
        queue.add(rootNode);
        while (!queue.isEmpty()){
            StateTreeNode temp = queue.poll();
            if (temp != null){
                applyOperators(temp);
                for (StateTreeNode child: temp.getChildren()) {
                    if(child != null){
                        queue.add(child);
                    }
                }
            }
            if(puzzleSolved || bfsStateLimitReached){
                break;
            }
        }
    }


    public void generateStateSpaceTreeIDS(StateTreeNode initialState) {
        int depthLimit = 0;
        while (!puzzleSolved){
            depthLimitedSearch(initialState, finalState, depthLimit);
            depthLimit += 1;
            exploredNodes.clear();
        }

    }

    private void depthLimitedSearch(StateTreeNode initialState, StateTreeNode finalState, int depthLimit){
        if(initialState.equals(finalState)){
            puzzleSolved = true;
            return;
        }
        if(depthLimit == 0){
            return;
        }
        if(initialState.getChildren().size() > 0){
            initialState.getChildren().clear();
        }
        applyOperators(initialState);
        for (StateTreeNode child: initialState.getChildren()){
            depthLimitedSearch(child, finalState, depthLimit - 1);
        }
    }


    public void printChildState(StateTreeNode rootNode){
        if(rootNode != null){
            if(dfsStateLimitReached || bfsStateLimitReached){
                System.out.println("Cannot solve.");
                System.out.println("No solutions found.");
                System.out.println("Over "+ STATE_LIMIT + " states explored.");
                System.out.println("Please use the bfs method to solve if you are using dfs.");
                System.out.println("if you are using bfs and cannot find the solution,");
                System.out.println("then the problem is probably unsolvable using bfs or dfs. :((");
            }else {
                int nodeLevel = 0;
                nodeLevel = rootNode.getLevel();
                String spacesForLevel = getSpace(nodeLevel * 3);
                String prefix = spacesForLevel + "|__";
                System.out.println(prefix + rootNode.toString());
                for (StateTreeNode childNode: rootNode.getChildren()) {
                    printChildState(childNode);
                }

            }
        }
    }

    private String getSpace(int numberOfSpace){
        return " ".repeat(Math.max(0, numberOfSpace));
    }

    private String addPathArrows(String stateReachingPath){
        int originalLength = stateReachingPath.length();
        int charAppendCount = 0;

        StringBuilder path = new StringBuilder();
        for (char c: stateReachingPath.toCharArray()) {
            path.append(c);
            if(charAppendCount < originalLength - 1){
                path.append(" -> ");
            }
            charAppendCount++;
        }
        return path.toString();
    }


    public boolean isPuzzleSolved() {
        return puzzleSolved;
    }

    public boolean isDfsStateLimitReached() {
        return dfsStateLimitReached;
    }

    public boolean isBfsStateLimitReached() {
        return bfsStateLimitReached;
    }

    private String findStateReachingPath(StateTreeNode node){
        StringBuilder reverser = new StringBuilder(node.findStateReachingPathFromRoot());
        return addPathArrows(reverser.reverse().toString());
    }
    public String getStateReachingPath() {
        return stateReachingPath;
    }

}
