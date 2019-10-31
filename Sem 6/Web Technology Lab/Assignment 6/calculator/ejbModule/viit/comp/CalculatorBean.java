package viit.comp;

import javax.ejb.Remote;
import javax.ejb.Stateless;

@Stateless(name="CalculatorBean")
@Remote(CalculatorBeanRemote.class)  
public class CalculatorBean implements CalculatorBeanRemote{
	public float add(float x, float y){	 
		return x + y;
   }

   public float subtract(float x, float y){
      return x - y;
   }
    public float multiply(float x, float y){
      return x * y;
   }
   public float division(float x, float y){
	   return x / y;
   }
}
