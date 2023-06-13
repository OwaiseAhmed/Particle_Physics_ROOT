
void muon_eta()

{

    TH1F *hist_muoneta  = new TH1F("Muon eta", "Muon_eta", 48, -6., 6.);

    auto file = TFile::Open("DYJetsToLL.root");

    auto Tree = (TTree*)file->Get("Events");
    
    hist_muoneta->GetXaxis()->SetTitle("Muon Eta");

    uint nmuon;
    int nentires = Tree->GetEntries();
    int max = 50;

    float muon_eta[max];

    Tree->SetBranchAddress("nMuon", &nmuon);
    Tree->SetBranchAddress("Muon_eta", muon_eta);
    

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < nmuon; j++)
        {

            hist_muoneta->Fill(muon_eta[j]);
        }
    }

    TCanvas *c8 = new TCanvas();
    hist_muoneta->Draw();

    return;
}
