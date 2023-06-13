void assignment1_tau(){

TH1F *hist_taus = new TH1F("Number of tauons", "hist", 100, -50, 50);

TFile *file = new TFile("DYJetsToLL.root");


TTree *tree1 = (TTree*)file->Get("Events");

unsigned int nTau;

tree1->SetBranchAddress("nTaus",&Muon_pt);

int nentries = (int)tree1->GetEntries();

for (int i =0;i<nentries;i++){

tree1->GetEntry(i);
hist_taus->Fill(nTau);

}

TCanvas *c1 = new TCanvas();
hist_taus->Draw();

return;

}
