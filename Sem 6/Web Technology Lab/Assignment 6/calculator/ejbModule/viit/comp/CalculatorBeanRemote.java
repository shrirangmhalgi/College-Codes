package viit.comp;

import javax.ejb.Remote;

@Remote
public interface CalculatorBeanRemote {

	 public float add(float x, float y);
	 public float subtract(float x, float y);
	 public float multiply(float x, float y);
	 public float division(float x, float y);
	
}
