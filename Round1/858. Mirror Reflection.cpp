class Solution {
public:
    int mirrorReflection(int p, int q) {

		double speedX = p;
		double speedY = q;
		double posX = 0;
		double posY = 0;
    	while(true) {
    		// cout << posX << " " << posY << " | " << speedX << " " << speedY <<endl;
    		double timeX = (speedX > 0)  ?((double)(p - posX))/(double)speedX : ((double)(-posX))/(double)speedX;
    		double timeY = (speedY > 0)  ?((double)(p - posY))/(double)speedY : ((double)(-posY))/(double)speedY;
    		// cout<<".   " << timeX << "  " << timeY << endl;
    		if(abs(timeX -timeY) < 0.00001) {
    			if(speedX > 0 && speedY > 0) {
    				return 1;
    			} else if(speedX < 0 && speedY > 0) {
    				return 2;
    			} else {
    			 return 0;
    			}
    		} else if(timeX < timeY) {
    			if(speedX > 0) {
    				posY += ((p-posX) * speedY /speedX);
    				posX = p;
    				speedX = -speedX;
    				speedY = speedY;
    			} else {
    				posY += ((-posX) * speedY /speedX);
    				posX = 0;
    				speedX = -speedX;
    				speedY = speedY;
    			}
    		} else {
    			if(speedY > 0) {
    				posX += ((p-posY) * speedX/speedY);
    				posY = p;
    				speedX = speedX;
    				speedY = -speedY;
    			} else {
    				posX += ((-posY) * speedX/speedY);
    				posY = 0;
    				speedX = speedX;
    				speedY = -speedY;
    			}
    		}
    	}
    	return -1;
    }
};