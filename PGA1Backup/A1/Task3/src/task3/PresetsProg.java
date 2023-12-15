package task3;

/**
 * Class that contains information related to different training programme presets available in 
 * the cross-trainer machine. These presets includes hill, cardio and fat-burn trining programee
 * presets
 */
public class PresetsProg {
    private Hill hillPreset; 
    private Cardio cardioPreset;
    private FatBurn fatBurnPreset;
    private static int presetCode = 1; //preset code for currently selected preset
    private TrainingGoals currentPresetGoal; //training goals for currently selected preset
   
    //constructor to initialize all the data fields of this class
    public PresetsProg(){
        this.hillPreset = new Hill();
        this.cardioPreset = new Cardio();
        this.fatBurnPreset = new FatBurn();
        currentPresetGoal = new TrainingGoals(this.hillPreset.getTrainingGoals()); //default selected preset
    }

    /**
     * Method that displays/cycles through the preset training goal target time, distance and resistance level
     * to the based on the integer code that represents 'next' (1) or 'last' (2) options.
     * @param nextOrLast an integer code representing next/last flags 
     */
    public void seePreset(int nextOrLast){
        
        if(nextOrLast == 1){
            if(presetCode >= 1 && presetCode < 3){
                presetCode++;
            }
        }

        if(nextOrLast == 2){
            if(presetCode > 1 && presetCode <= 3){
                presetCode--;
            }
        }
        
        switch(presetCode){
            case 1:
                System.out.println("\nPreset Type: Hill");
                System.out.println(this.hillPreset.getTrainingGoals().toString());
                break;
            case 2:
                System.out.println("\nPreset Type: Cardio");
                System.out.println(this.cardioPreset.getTrainingGoals().toString());
                break;
            case 3:
                System.out.println("\nPreset Type: Fat-Burn");
                System.out.println(this.fatBurnPreset.getTrainingGoals().toString());
                break;
            default:
                System.out.println("No matching presets found. Default: Hill preset selected");
                break;
        }
    }


    /**
     * Method that returns the training goals of preset currently selected dependig upon the currently 
     * selected preset code. Preset codes: 1 -> Hill, 2 -> Cardio, 3 -> Hill
     * @return a TrainingGoals (includes, target distance, time and ressistance) currently selected preset
     */
    public TrainingGoals getCurrentPresetGoal(){
        if(presetCode == 2){
            return new TrainingGoals(this.cardioPreset.getTrainingGoals());
        }else if(presetCode == 3){
            return new TrainingGoals(this.fatBurnPreset.getTrainingGoals());
        }else{
            return this.currentPresetGoal; //returns the default preset: Hill Preset
        }
    }

    /**
     * Method that returns the name of preset currently selected dependig upon the currently 
     * selected preset code. Preset codes: 1 -> Hill, 2 -> Cardio, 3 -> Hill
     * @return a string representing the name of currently selected preset
     */
    public String getPresetType(){
        if(presetCode == 2){
            return "Cardio";
        }else if(presetCode == 3){
            return "Fat-Burn";
        }else{
            return "Hill";
        }
    }

    /**
     * Class containing all the information reletaed to the hill training program preset.
     */
    private class Hill{
        private TrainingGoals hillTrainGoals; //Target training goals for the hill training preset
        
        private Hill(){
            this.hillTrainGoals = new TrainingGoals(3000, 20, 28);
        }

        private TrainingGoals getTrainingGoals(){
            return this.hillTrainGoals;
        }

    }


    /**
     * Class containing all the information reletaed to the Cardio training program preset.
     */
    private class Cardio{
        private TrainingGoals cardioTrainGoals; //Target training goals for the Cardio training preset

        private Cardio(){
            this.cardioTrainGoals = new TrainingGoals(9000, 50, 25);
        }

        private TrainingGoals getTrainingGoals(){
            return this.cardioTrainGoals;
        }
    }

    /**
     * Class containing all the information reletaed to the Fat-Burn training program preset.
     */
    private class FatBurn{
        private TrainingGoals fatBurnTrainGoals; //Target training goals for the Fat-Burn training preset

        private FatBurn(){
            this.fatBurnTrainGoals = new TrainingGoals(7000, 45, 15);
        }

        private TrainingGoals getTrainingGoals(){
            return this.fatBurnTrainGoals;
        }
    }
}
