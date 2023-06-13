int absolute(float number){

if (number>0){
    return number;
}

else
    return -1*number;
}


void prob3_c(){

// declaring the histogram
TH1F* hist_prob3_c = new TH1F("Histogram", "step 3", 100, 0.,300.);

// opening the root file named DYJetsToLL
auto file  = TFile::Open("DYJetsToLL.root");

// declaring Tree and assign to it the tree named Events
auto Tree = (TTree*)file->Get("Events");


//total number of collisions made 
int nentires = Tree->GetEntries();


//declaring the component of the 4 vetor 
int tau_charge[50];
float tau_mass[50];
float tau_pt[50];
float tau_eta[50];
float tau_phi[50];
bool tau_idDecayMode[50];
bool tau_idIsoTight[50];

//Declaring the invariant mass
float inv_mass_tau[50];

//getting the branches of the Tree
Tree->SetBranchAddress("Tau_pt", tau_pt);
Tree->SetBranchAddress("Tau_eta",tau_eta);
Tree->SetBranchAddress("Tau_phi",tau_phi);
Tree->SetBranchAddress("Tau_mass",tau_mass);
Tree->SetBranchAddress("Tau_charge", tau_charge);
Tree->SetBranchAddress("Tau_idDecayMode", tau_idDecayMode);
Tree->SetBranchAddress("Tau_idIsoTight", tau_idIsoTight);




//declaring lorentz vector for the tow leading taus and the for the addition vector
TLorentzVector lvectau1, lvectau2, lvecZ;

for (int i = 0; i < int(nentires); i++){

        // getting the data from the ith collision
        Tree->GetEntry(i);

	// vector addition of the two lorentz vector
    if (tau_charge[0]*tau_charge[1]<0 && absolute(tau_eta[0]) < 2.3 && tau_pt[0]  > 20 && tau_idDecayMode[0] == true && tau_idIsoTight[0] == true && tau_idDecayMode[1] == true && tau_idIsoTight[1] == true){
        
        // flling up the 4 vector for the leading particle
        lvectau1.SetPtEtaPhiM(tau_pt[0],tau_eta[0],tau_phi[0],tau_mass[0]);     
        lvectau2.SetPtEtaPhiM(tau_pt[1],tau_eta[1],tau_phi[1],tau_mass[1]);
        
        lvecZ = lvectau1+lvectau2;
        float di_tau_mass = lvecZ.Mag(); // invariant mass
	
	    // filling up the histogrm prob2_hist
        hist_prob3_c->Fill(di_tau_mass);
            
    
    }

}

TF1 f("FIT","gaus");

hist_prob3_c->Fit(&f,"","",55.,120);

// seting up the canvas
TCanvas *canvas = new TCanvas();

// drawing the histogram
hist_prob3_c->Draw();



return;

}

