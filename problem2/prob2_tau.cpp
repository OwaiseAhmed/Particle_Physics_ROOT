void prob2_tau(){
	
	
//declaring a histogram
TH1F* prob2_hist = new TH1F("Invariant mass Tau", "Tau mass", 100,0.,300.);

//opening the root file
auto file = TFile::Open("DYJetsToLL.root");

prob2_hist->GetXaxis()->SetTitle("Invariant mass, Gev");

//getting the Tree named event and storing it in the variable Tree
auto Tree = (TTree*)file->Get("Events");

//total number of collisions made 
int nentires = Tree->GetEntries();

//decalring the number of tuas, no use
unsigned int ntau;

//declaring the component of the 4 vetor 
float tau_mass[50];
float tau_pt[50];
float tau_eta[50];
float tau_phi[50];

//Declaring the invariant mass
float inv_mass_tau[50];

//getting the branches of the Tree
Tree->SetBranchAddress("nTau",&ntau);
Tree->SetBranchAddress("Tau_pt", tau_pt);
Tree->SetBranchAddress("Tau_eta",tau_eta);
Tree->SetBranchAddress("Tau_phi",tau_phi);
Tree->SetBranchAddress("Tau_mass",tau_mass);


//declaring lorentz vector for the tow leading taus and the for the addition vector
TLorentzVector lvectau1, lvectau2, lvecZ;

for (int i = 0; i < int(nentires); i++){

        // getting the data from the ith collision
        Tree->GetEntry(i);
        
        // flling up the 4 vector for the leading particle
        lvectau1.SetPtEtaPhiM(tau_pt[0],tau_eta[0],tau_phi[0],tau_mass[0]);     
        lvectau2.SetPtEtaPhiM(tau_pt[1],tau_eta[1],tau_phi[1],tau_mass[1]);

	// vector addition of the two lorentz vector
        lvecZ = lvectau1+lvectau2;


        float di_tau_mass = lvecZ.Mag(); // invariant mass
	
	// filling up the histogrm prob2_hist
        prob2_hist->Fill(di_tau_mass);
            
      

    }
    
    TF1 f("FIT","gaus");

// seting up the canvas
TCanvas *canvas = new TCanvas();
prob2_hist->Fit(&f,"","",55.,120.);
// drawing the histogram
prob2_hist->Draw();

return;

}

