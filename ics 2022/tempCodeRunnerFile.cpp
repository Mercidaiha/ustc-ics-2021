for(int i=12; i<16; i++){
        if(score[i] >= 85){
            result_a = result_a + 1;
        }
    }
    for(int i=8; i<16; i++){
        if(score[i] >= 75){
            result_ab = result_ab + 1;
        }
    }
    result_b = result_ab - result_a;