
void muonphi()

{

    TH1F *hist_muonphi  = new TH1F("Muon Phi", "Muon phi", 100, -4., 4.);

hist_muonphi->GetXaxis()->SetTitle("Muon Phi, radian");


    auto file = TFile::Open("DYJetsToLL.root");

    auto Tree = (TTree*)file->Get("Events");

    uint nmuon;
    int nentires = Tree->GetEntries();
    int max = 50;

    float muon_phi[max];

    Tree->SetBranchAddress("nMuon", &nmuon);
    Tree->SetBranchAddress("Muon_phi", muon_phi);

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < nmuon; j++)
        {

            hist_muonphi->Fill(muon_phi[j]);
        }
    }

    TCanvas *c5 = new TCanvas();
    hist_muonphi->Draw();

    return;
}
