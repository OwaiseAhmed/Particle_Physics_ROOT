

void muonpt()
{

    TH1F *hist_muonpt  = new TH1F("Muon Pt", "Muon Pt", 100, 0., 300.);

hist_muonpt->GetXaxis()->SetTitle("Muon Pt, Gev/c");

    auto file = TFile::Open("DYJetsToLL.root");

    auto Tree = (TTree*)file->Get("Events");
    
    uint nmuon;
    int nentires = Tree->GetEntries();
    int max = 50;

    float Muon_pt[max];

    Tree->SetBranchAddress("nMuon", &nmuon);
    Tree->SetBranchAddress("Muon_pt", Muon_pt);

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < nmuon; j++)
        {
	    if (Muon_pt[j]<150){
            hist_muonpt->Fill(Muon_pt[j]);
            }
        }
    }

    TCanvas *c3 = new TCanvas();
    hist_muonpt->Draw();

    return;
}
