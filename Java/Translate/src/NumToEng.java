
public class NumToEng {
    static String English;
    public static String translate(int num){
        English="";
        int unit=num%10;
        int tens=num/10;
        return English=EngString.tens[tens]+" "+EngString.unit[unit];
    }
}
