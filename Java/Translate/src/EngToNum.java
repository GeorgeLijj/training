public class EngToNum {
    static int number;
    public static int translate(String Eng){
        number=0;
        String tens="",unit="";
        int pos=Eng.indexOf(' ');
        if(pos!=-1){
            tens=Eng.substring(0,pos);
            unit=Eng.substring(pos+1);
        }else{
            tens="";
            unit=Eng;
        }
        for(int i=2;i<10;i++){
            if(EngString.tens[i].equals(tens)){
                number+=i*10;
                break;
            }
        }
        for(int i=0;i<20;i++){
            if(EngString.unit[i].equals(unit)){
                number+=i;
                break;
            }
            if(EngString.tens[i].equals(unit)){
                number+=i*10;
                break;
            }
        }
        return number;
    }
}
