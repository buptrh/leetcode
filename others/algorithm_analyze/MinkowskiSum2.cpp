int MinkowskiSum2(vector<int> X, vector<int> Y, int M) {
	//1.transform to coefficient representation and Double degree-bound
	//because degrees can't be negative, so add all degrees by M. and we need to double the degree before we start FFT.
	vector<int> Ax(M*4, 0), Ay(M*4, 0);
	for(int i = 0; i < X.size(); i++) {
		Ax[X[i] + M] = 1;
	}
	for(int i = 0; i < Y.size(); i++) {
		Ay[Y[i] + M] = 1;
	}

	//2.Evaluate with FFT
	vector<int> Bx = RECURSIVE_FFT(Ax);
	vector<int> By = RECURSIVE_FFT(Ay);

	//3.Pointwise Multiply
	vector<int> C(M*4, 0);
	for(int i = 0; i < M*4; i++) {
		C[i] = Bx[i] * By[i];
	}

	//4.Interpolate
	vector<int> D = INVERSE_DFT(C);

	//5.Calculate Non-zero Coefficient
	int output = 0;
	for(int i = 0; i < D.size(); i++) {
		if(D[i] != 0) {
			output++;
		}
	}

	return output;


}