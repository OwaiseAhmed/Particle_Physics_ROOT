void problem2_muon(){


TH1F* prob2_hist = new TH1F("histogra for invariant mass of muon", "Hstogram", 50,-0.5,49.5);

auto file = TFile::Open("DYJetsToLL.root");

auto Tree = (TTree*)file->Get("Events");

int nentires = Tree->GetEntries();
unsigned int nmuon;


float muon_mass[50];
float muon_pt[50];
float muon_eta[50];
float muon_phi[50];


float inv_mass_muon[50];

Tree->SetBranchAddress("Moun_mass", muon_mass);
Tree->SetBranchAddress("nMuon",&nmuon);
Tree->SetBranchAddress("Muon_pt", muon_pt);
Tree->SetBranchAddress("Muon_eta",muon_eta);
Tree->SetBranchAddress("Muon_phi",muon_phi);
Tree->SetBranchAddress("Muon_mass",muon_mass);


TLorentzVector lvecmuon1, lvecmuon2, lvecZ;

for (int i = 0; i < int(nentires); i++){

        Tree->GetEntry(i);
        
        for ( int i =0;i<2;i++){
            lvecmuon1.SetPtEtaPhiM(muon_pt[0],muon_eta[0],muon_phi[0],muon_mass[0]); 
            
            lvecmuon2.SetPtEtaPhiM(muon_pt[1],muon_eta[1],muon_phi[1],muon_mass[1]);

            lvecZ = lvecmuon1+lvecmuon2;

            float di_muon_mass = lvecZ.Mag(); // invariant mass
            prob2_hist->Fill(di_muon_mass)
        TCanvas *canvas = new TCanvas()
        prob2_hist->Draw();
        
	}

    }





return;

}

