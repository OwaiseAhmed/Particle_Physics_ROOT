void prob2_muon(){


// Decalring a histogram
TH1F* prob2_hist = new TH1F("Muon mass", "Invariant mass Muon", 100,0.,200.);

//opening a file
auto file = TFile::Open("DYJetsToLL.root");


// getting the tree from the file
auto Tree = (TTree*)file->Get("Events");

prob2_hist->GetXaxis()->SetTitle("Invariant mass, Gev");

// total number of "collisions"
int nentires = Tree->GetEntries();

// number of muon
unsigned int nmuon;

// declaring the components of the 4-Vector
float muon_mass[50];
float muon_pt[50];
float muon_eta[50];
float muon_phi[50];

// declaring the invariant mass
float inv_mass_muon[50];

// getting Data from the branches of the tree Tree
Tree->SetBranchAddress("nMuon",&nmuon);
Tree->SetBranchAddress("Muon_pt", muon_pt);
Tree->SetBranchAddress("Muon_eta",muon_eta);
Tree->SetBranchAddress("Muon_phi",muon_phi);
Tree->SetBranchAddress("Muon_mass",muon_mass);


// Declaring lorentz vector in order 
TLorentzVector lvecmuon1, lvecmuon2, lvecZ;

for (int i = 0; i < int(nentires); i++){

	// get entry is somewhat getting the data in the 1st collision
        Tree->GetEntry(i);
        
       	 
       	// for filling the lorentz vetor with 0th particle 
        lvecmuon1.SetPtEtaPhiM(muon_pt[0],muon_eta[0],muon_phi[0],muon_mass[0]); 
        
        // for filling the lorentz vetor with 1st particles    
        lvecmuon2.SetPtEtaPhiM(muon_pt[1],muon_eta[1],muon_phi[1],muon_mass[1]);
        
        // total momentum offered by the leading two muon
        lvecZ = lvecmuon1+lvecmuon2;

	// finding the invaiant mass of the two muons
        float di_muon_mass = lvecZ.Mag(); // invariant mass
         
        // Filling up the histogram with invariant masses
        prob2_hist->Fill(di_muon_mass);
            
      
    }

TF1 f("FIT","gaus");

//Fit function requires 4 arguments
// last two are the range of the gauss
prob2_hist->Fit(&f,"","",65.,120.);
// Declaring a canvass
TCanvas *canvas = new TCanvas();

// Drawing the histogram
prob2_hist->Draw();




return;

}


// steps 
// for each step find the value of resolution and error

